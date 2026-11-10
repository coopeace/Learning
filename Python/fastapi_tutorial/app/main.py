from fastapi import Depends, FastAPI, HTTPException, Query, status
import psycopg2
from psycopg2.extras import RealDictCursor
import os
from typing import Annotated, Optional
from .database import engine,get_db
from . import models,schema
from sqlalchemy.orm import Session

models.Base.metadata.create_all(bind=engine)

app = FastAPI(title="Youtube Tutorial",
              version="0.1.0",
              docs_url="/docs")

# load_dotenv()
# database_url = os.getenv('DATABASE_URL')
#
# try:
#     conn = psycopg2.connect(dsn=database_url,cursor_factory=RealDictCursor)
#     cursor = conn.cursor()
#     print("Database connection was successful")
# except Exception as error:
#     print("Connecting to database failed")
#     print("Error:",error)

@app.get("/",description="Root endpoint of the api")
def root():
    return { "result" : "Welcome to Tutorial!!" }

@app.get("/posts",response_model=list[schema.PostResponse])
def get_posts(db : Session = Depends(get_db),limit : Annotated[int|None,Query(ge=1,le=30)]=None):
    #limit: Annotated[int|None,Query(ge=1,le=30)]=None
    # cursor.execute('''SELECT * FROM Posts LIMIT %s''',(limit,))
    # posts = cursor.fetchall()
    posts = db.query(models.Post).limit(limit).all()
    return posts

# @app.get("/posts/latest",status_code=status.HTTP_200_OK)
# def get_last_post():
#     cursor.execute("""SELECT * FROM Posts ORDER BY created_at DESC LIMIT 1""")
#     lastest_post = cursor.fetchone()
#     if lastest_post == None:
#         raise HTTPException(
#                 status_code=status.HTTP_404_NOT_FOUND,
#                 detail="No Posts Found in the Database"
#                 )
#     return { 
#             "message" : "Lastest Post Found",
#             "result" : lastest_post
#             }
#
@app.get("/posts/{id}",response_model=schema.PostResponse)
def get_post_by_id(id : int,db : Session = Depends(get_db)):
    # cursor.execute("""SELECT * FROM posts WHERE id=%s""",str(id))
    # post = cursor.fetchone()
    post = db.query(models.Post).filter(models.Post.id == id).first()
    if not post:
        raise HTTPException(
                status_code  = status.HTTP_404_NOT_FOUND,
                detail = f"Post with id {id} not found"
                )
    return post

@app.post("/posts",status_code=status.HTTP_201_CREATED,response_model=schema.PostResponse)
def create_post(post : schema.PostCreate,db : Session = Depends(get_db)):
    # cursor.execute("""INSERT INTO Posts (title,content,published) VALUES (%s,%s,%s) Returning *""",
    #                (post.title,post.content,post.published))
    # new_post = cursor.fetchone()
    new_post = models.Post(**post.model_dump())
    db.add(new_post)
    db.commit()
    db.refresh(new_post)
    if not new_post:
        raise HTTPException(
                status_code=status.HTTP_400_BAD_REQUEST,
                detail= "Post not created"
                )
    # conn.commit()
    return new_post

@app.delete("/posts/{id}",status_code=status.HTTP_204_NO_CONTENT)
def delete_post(id : int, db : Session = Depends(get_db)):
    # cursor.execute("""DELETE FROM Posts WHERE id=%s RETURNING *""",str(id))
    # deleted_post = cursor.fetchone()
    # print(deleted_post)
    post_query = db.query(models.Post).filter(models.Post.id == id)
    if post_query.first() == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND,detail=f"post of id {id} not exists")
    # conn.commit()
    post_query.delete(synchronize_session = False)
    db.commit()
    return HTTPException(status_code=status.HTTP_204_NO_CONTENT)

@app.put("/posts/{id}",response_model=schema.PostResponse)
def update_post(id : int,updated_post : schema.PostCreate,db : Session = Depends(get_db)):
    # cursor.execute("""UPDATE Posts SET title=%s,content=%s,published=%s WHERE id=%s RETURNING *""",
    #                (post.title,post.content,post.published,str(id)))
    # updated_post = cursor.fetchone()
    post_query = db.query(models.Post).filter(models.Post.id == id)
    post = post_query.first()
    if post == None :
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND,detail=f"post of id {id} does not exists")
    post_query.update(updated_post.model_dump(),synchronize_session = False)
    db.commit()
    return post_query.first()

@app.post("/users",status_code=status.HTTP_201_CREATED,response_model=schema.UserReponse)
def create_user(user : schema.UserCreate,db : Session = Depends(get_db)):
    new_user = models.User(**user.model_dump())
    db.add(new_user)
    db.commit()
    db.refresh(new_user)

    return new_user



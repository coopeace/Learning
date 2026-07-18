from fastapi import FastAPI,HTTPException
from typing import Any
import database
from pydantic import BaseModel

import database

app = FastAPI()

class UserCreate(BaseModel):
    username : str
    age : int

@app.get("/")
async def root():
    return {"message":"Hello World"}
    
@app.get("/items/{item_id}")
async def read_items(item_id : int , q: str | None = None):
    results : dict[str,Any] = {"item_id" : item_id}

    if q:
        results.update({"query":q})

    return results

@app.get("/db-users")
async def read_db_users():
    data = database.get_all_users()
    
    # Check if the list is empty
    if not data:
        return {
            "status": "success",
            "message": "Connection works, but the 'users' table is currently empty.",
            "database_content": []
        }
        
    return {"database_content": data}

@app.post("/users")
async def add_user(user : UserCreate):
    try : 
        new_user_id = database.create_user(user.username,user.age)
        return {
                "status" : "success",
                "message" : f"User created with Id : {new_user_id}"
        }

    except Exception as e:
        print(f"Error: {e}")
        raise HTTPException(status_code=400,detail = "Could not create user.Username might already exist.")

@app.put("/users/{user_id}")
async def update_user(user_id: int, new_age: int):
    updated_id = database.update_user_age(user_id, new_age)
    if not updated_id:
        raise HTTPException(status_code=404, detail="User not found")
    return {"message": f"User {updated_id} updated successfully"}

@app.delete("/users/{user_id}")
async def remove_user(user_id: int):
    deleted_id = database.delete_user(user_id)
    if not deleted_id:
        raise HTTPException(status_code=404, detail="User not found")
    return {"message": f"User {deleted_id} deleted successfully"}

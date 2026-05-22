import os
import psycopg2
from dotenv import load_dotenv
from psycopg2.extras import RealDictCursor
from contextlib import contextmanager

load_dotenv()

@contextmanager
def get_db_cursor():
    dsn = os.getenv("DATABASE_URL")
    conn = psycopg2.connect(dsn)
    cur = conn.cursor(cursor_factory=RealDictCursor)
    try:
        yield cur
        conn.commit()
    except Exception as e:
        conn.rollback()
        raise e
    finally:
        cur.close()
        conn.close()

def get_db_connection():
    try: 
        dsn = os.getenv("DATABASE_URL")
        conn = psycopg2.connect(dsn)
        # Log the connection details to your uvicorn terminal
        print(f"--- Connected to Database: {conn.info.dbname} as User: {conn.info.user} ---")
        return conn
    except Exception as e:
        print(f"Connection failed: {e}")
        return None

def get_all_users():
    conn = get_db_connection()
    if not conn:
        return []

    try:
        cur = conn.cursor(cursor_factory=RealDictCursor)
        
        # We use the full path 'public.users' to ensure we aren't 
        # looking in a different schema by mistake.
        cur.execute("SELECT * FROM public.users;")
        
        users = cur.fetchall()
        print(f"--- Query executed. Found {len(users)} rows. ---")
        
        cur.close()
        conn.close()
        return users
    except Exception as e:
        print(f"Query error: {e}")
        return []

def create_user(username :str,age : int):
    with get_db_cursor() as cur:
        sql = "INSERT INTO public.users(username,age) VALUES (%s,%s) RETURNING id;"
        cur.execute(sql,(username,age))

        result = cur.fetchone()
        if result is None:
            return None
        return result['id']

def update_user_age(user_id : int,new_age : int):
    with get_db_cursor() as cur:
        sql = "UPDATE public.users SET age = %s WHERE id = %s RETURNING id;"
        cur.execute(sql,(new_age,user_id))
        result = cur.fetchone()
        return result['id'] if result else None

def delete_user(user_id: int):
    with get_db_cursor() as cur:
        sql = "DELETE FROM public.users WHERE id = %s RETURNING id;"
        cur.execute(sql,(user_id,))
        result = cur.fetchone()
        return result['id'] if result else None

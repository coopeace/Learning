import psycopg2
from psycopg2.extras import RealDictCursor

def get_db_connection():
    # This is like setting up a socket connection to the DB
    conn = psycopg2.connect(
        host="localhost",
        database="postgres", # Default DB name
        user="postgres",     # Default user
        password="your_password" # If you set one
    )
    return conn

def get_all_users():
    conn = get_db_connection()
    # RealDictCursor makes results look like Python Dictionaries {}
    cur = conn.cursor(cursor_factory=RealDictCursor)
    
    # Sending the exact SQL command you just learned!
    cur.execute("SELECT * FROM users;")
    
    users = cur.fetchall()
    
    cur.close()
    conn.close()
    return users

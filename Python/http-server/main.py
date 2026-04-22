from fastapi import FastAPI
from typing import Any

app = FastAPI()

@app.get("/")
async def root():
    return {"message":"Hello World"}
    
@app.get("/items/{item_id}")
async def read_items(item_id : int , q: str | None = None):
    results : dict[str,Any] = {"item_id" : item_id}

    if q:
        results.update({"query":q})

    return results

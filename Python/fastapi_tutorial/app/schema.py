from pydantic import BaseModel, ConfigDict,EmailStr
from datetime import datetime

class PostBase(BaseModel):
    title : str 
    content : str 
    published : bool = True

class PostCreate(PostBase):
    pass

class PostResponse(PostBase):
    id : int
    created_at : datetime
    
    # class Config : 
    #     from_attributes = True
    model_config = ConfigDict(from_attributes=True)

class UserCreate(BaseModel):
    email : EmailStr
    password : str

class UserReponse(BaseModel):
    id : int
    email : EmailStr
    created_at : datetime

    model_config = ConfigDict(from_attributes=True)

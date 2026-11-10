### Create Table
- create table Products (
    name varchar(255) NOT NULL,
    price float NOT NULL,
    id UNIQUE PRIMARY KEY
);

### INSERT Row 
- insert into products (name,price) values ('TV',200);

### Alter Row
- alter table products add column on_sale boolean default false;

### Update Row 
- update products set id = 5 where name = 'Microphone';

### Ownership and Password
- (Ownership) ALTER DATABASE fastapi_tutorial OWNER TO coopeace;
- (password) ALTER ROLE coopeace WITH PASSWORD 'merry123';
- GRANT pg_database_owner TO coopeace;

### View Table Schema
- \d <table_name>
- \d+ <table_name> (detailed such as storage,compression)

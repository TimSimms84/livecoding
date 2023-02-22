# Introduction

This is a simple example of using SQLAlchemy to define a one-to-many relationship between users and their addresses. This was from a live coding at Holberton Tulsa 2/22/2023.

## Prequites

Before running this program, make sure that you have the following installed:

Python 3
Python3-dev
Libmysqlclient
Zlib1g-dev
SQLAlchemy
MySQL (or another database supported by SQLAlchemy)
MySQLdb


## Running the program

To run the program, simply execute the main.py script with Python. This will create the necessary tables in the MySQL database and add some example data.

```python
python3 main.py
```

## Code Overview

This project contains the following files:

* base.py: Defines a declarative base for SQLAlchemy models.

* user.py: Defines the User model, which has a one-to-many relationship with the Address model.

* address.py: Defines the Address model, which belongs to a User.

* main.py: Sets up the database connection and performs some example queries.

## Example Queries

```python
# Add a new user
user = User(name='John Doe')
session.add(user)
session.commit()

# Add a new address for the user
address = Address(email='john.doe@example.com', user=user)
session.add(address)
session.commit()

# Retrieve all users
users = session.query(User).all()

# Retrieve all addresses for a user
user = session.query(User).filter_by(name='John Doe').first()
addresses = user.addresses
```

## Google Slideshow of Live Coding

[Link](https://docs.google.com/presentation/d/11I-0CjejzrqTU7Eafj2RglBTIIZBHyVnnpJl2KLfhGA/edit?usp=sharing)

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from base import Base
from user import User
from address import Address

# make sure the mysql database exist before running this code
engine = create_engine('mysql+mysqldb://root:root@localhost:3306/music')
Base.metadata.create_all(engine)

Session = sessionmaker(bind=engine)
session = Session()

# Example usage:
user1 = User(name='Chad')
address1 = Address(email='chad@email.com', user=user1)
session.add(user1)
session.add(address1)
session.commit()

user2 = User(name='Bob')
address2 = Address(email='bob@hotmail.com', user=user2)
session.add(user2)
session.add(address2)
session.commit()

for user in session.query(User).all():
    print(user.name)
    for address in user.addresses:
        print(address.email)

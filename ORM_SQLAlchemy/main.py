from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from base import Base
from Address import Address
from User import User

engine = create_engine('mysql+mysqldb://root:root@localhost:3306/music')
Base.metadata.create_all(engine)

Session = sessionmaker(bind=engine)
session = Session()

user1 = User(name="Chad")
address1 = Address(email="chad@holbertonschool.com")
session.add(user1)
session.add(address1)
session.commit()


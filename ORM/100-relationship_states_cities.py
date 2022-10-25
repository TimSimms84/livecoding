#!/usr/bin/python3
""" doc string """

if __name__ == "__main__":
    from sys import argv
    from sqlalchemy import create_engine
    from relationship_city import City
    from relationship_state import Base, State
    from sqlalchemy.orm import sessionmaker

    engine = create_engine('mysql+mysqldb://{}:{}@localhost/{}'.format(
        argv[1], argv[2], argv[3]), pool_pre_ping=True)
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()
    new_state = State(name="California", cities=[City(name="San Francisco")])
    session.add(new_state)
    session.commit()
    session.close()

#!/usr/bin/python3
"""
python file that contains the class definition of a City
and an instance Base = declarative_base()
"""
from sqlalchemy import Column, ForeignKey, Integer, String
from sqlalchemy.ext.declarative import declarative_base
from relationship_state import Base


class City(Base):
    """
    Creates the City class
    """
    __tablename__ = 'cities'
    id = Column(Integer, primary_key=True)
    name = Column(String(128), nullable=False)
    state_id = Column(Integer, ForeignKey('states.id'))

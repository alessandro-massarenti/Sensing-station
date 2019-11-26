# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File classe plant
# È stato costruito da Alessandro Massarenti
# V 2.0

from db_class import *


class Plant:
    database = db

    def __init__(self, database: Db):
        self.database = database

    def getAirTemp(self) -> float:
        return self.database.get_data("temp")[0]

    def getAirHumid(self) -> float:
        return self.database.get_data("umid")[0]

# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File classe plant
# È stato costruito da Alessandro Massarenti
# V 2.0

from db_class import *


class Plant:

    def getAirTemp(self, database: Db) -> float:
        return database.get_data("temp")[0]

    def getAirHumid(self, database: Db) -> float:
        return database.get_data("umid")[0]

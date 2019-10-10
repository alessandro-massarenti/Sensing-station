# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File classe database
# È stato costruito da Alessandro Massarenti
# V 2.0


import mysql.connector


class Db:
    host = "localhost"
    user = "datatest"
    passwd = "cacconaZizzona"
    database = "datatest"

    def __init__(self):
        self.my_db = mysql.connector.connect(self.host, self.user, self.passwd, self.database)

    def savedata(self, temp, humid):
        c = self.my_db.cursor()
        sql = "INSERT INTO dati (temp, umid) VALUES (%s, %s)"
        val = (temp, humid)
        c.execute(sql, val)
        self.my_db.commit()
        print(c.rowcount, "record inserted.")
        c.close()

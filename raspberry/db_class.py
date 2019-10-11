# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File classe database
# È stato costruito da Alessandro Massarenti
# V 2.0


import mysql.connector


class Db:
    
    host = "localhost"
    user = "datatest"
    passwd = "eJPB0U0Wf7EfZw5e"
    database = "datatest"

    # Constructor

    def __init__(self):
        self.my_db = mysql.connector.connect(host = self.host, user = self.user, passwd = self.passwd, database = self.database)
        print("mi sono connesso al db")
        self._check_entry_table()
    
    # Methods

    def _check_entry_table(self):
        c = self.my_db.cursor()

    def savedata(self, temp, humid):
        c = self.my_db.cursor()
        sql = "INSERT INTO dati (temp, umid) VALUES (%s, %s)"
        val = (temp, humid)

        c.execute(sql, val)
        c.commit()

        print(c.rowcount, "record inserted.")
        c.close()
    
    def get_data(self, data):
        c = db.cursor()
        sql = "SELECT %s FROM dati ORDER BY id DESC LIMIT 1"
        val = (data)
        c.execute(sql,val)
        data = c.fetchone()
        db.commit()
        return data

    def get_temp(self):
        get_data("temp")

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
    my_db = None

    # Constructor

    def __init__(self):
        self.my_db = mysql.connector.connect(
            host=self.host, user=self.user, passwd=self.passwd, database=self.database)
        print("mi sono connesso al db")
        self._check_entry_table()

    # Methods

    def _check_entry_table(self):
        c = self.my_db.cursor()
        sql = "SELECT FROM dati"
        sql =   "CREATE TABLE `dati` (\
                `id` int(11) NOT NULL,\
                `temp` float NOT NULL,\
                `umid` float NOT NULL,\
                `time` timestamp NOT NULL DEFAULT current_timestamp())\
                ENGINE = InnoDB DEFAULT CHARSET = utf8mb4"

    def savedata(self, temp, humid):
        c = self.my_db.cursor()
        sql = "INSERT INTO dati (temp, umid) VALUES (%s, %s)"
        val = (temp, humid)

        c.execute(sql, val)
        self.my_db.commit()

        print(c.rowcount, "record inserted.")
        c.close()

    def get_data(self, sensor: str):
        c = self.my_db.cursor()
        sql = "SELECT "+sensor+" FROM dati ORDER BY id DESC LIMIT 1"

        c.execute(sql)
        data: float = c.fetchone()
        
        self.my_db.commit()
        print (data)
        return data
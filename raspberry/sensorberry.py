# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File principale
# È stato costruito da Alessandro Massarenti
# V 2.0


import serial
import db_class

db = Db()

ser = serial.Serial('/dev/ttyUSB0', 9600)
while True:
    data = ser.readline().decode('utf8')

    data = data.split(',')
    print(data)

    temp = float(data[1][:4])
    humid = float(data[0])

    db.savedata(temp, humid)

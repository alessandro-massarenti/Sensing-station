import serial

import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="datatest",
    passwd="cacconaZizzona",
    database="datatest"
)



def savedata(temp,humid):
    c = mydb.cursor()
    sql = "INSERT INTO dati (temp, umid) VALUES (%s, %s)"
    val = (temp, humid)
    c.execute(sql, val)
    mydb.commit()
    print(c.rowcount, "record inserted.")
    c.close()

ser = serial.Serial('/dev/ttyUSB0', 9600)
while True:
    data = ser.readline().decode('utf8')

    data = data.split(',')
    print(data)

    temp =float(data[1][:4])
    humid = float(data[0])
    
    savedata(temp,humid)

    

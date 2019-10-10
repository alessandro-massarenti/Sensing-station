# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File principale
# È stato costruito da Alessandro Massarenti
# V 2.0


from db_class import *
from sensor_class import *
from bot_class import *

db = Db()
th_sensor = Sensor("USB0")

# Fa andare l' ascolto degli imput come un thread separato.
MessageLoop(bot, {'chat': on_chat_message}).run_as_thread()

while True:
    
    th_data = th_sensor.get_data()

    print(th_data)

    temp = float(th_data[1][:4])
    humid = float(th_data[0])

    db.savedata(temp, humid)

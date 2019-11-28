# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File principale
# È stato costruito da Alessandro Massarenti
# V 2.0

import threading
import time

import serial
from telepot.loop import MessageLoop
from telepot.namedtuple import ReplyKeyboardMarkup, KeyboardButton

from config import *
from funzioni import *
from plant_class import *

# Handle input
usb = "USB0"
serial = serial.Serial('/dev/tty' + usb, 9600)
if serial.isOpen():
    serial.close()
serial.open()
serial.isOpen()


def save_data_routine():
    while 1:
        time.sleep(10)

        ambient_temp = get_data("temp", serial)
        ambient_humidity = get_data("humi", serial)
        Db.savedata(ambient_temp, ambient_humidity)


Db.check_entry_table()
avocado = Plant()


def msg_handler(msg):
    content_type, chat_type, chat_id = telepot.glance(msg)
    user_id = msg['from']['id']

    if content_type == 'text':
        comando = msg['text']
        if comando == '/start':
            bot.sendMessage(chat_id, text="Scegli un bottone", reply_markup=ReplyKeyboardMarkup(
                keyboard=[
                    [KeyboardButton(text='avocado')],
                ]))

        elif comando == 'avocado':
            airtemp = str(avocado.getAirTemp())
            airhumid = str(avocado.getAirHumid())
            message: str = "Avocado:\nT. aria: " + \
                           airtemp + "°C\n" + "U. aria: " + airhumid + "%"
            bot.sendMessage(chat_id, text=message)
            print("ho risposto al comando avocado di:" + str(user_id))


MessageLoop(bot, msg_handler).run_as_thread()
print('Listening ...')

x = threading.Thread(target=save_data_routine)
x.start()

# Mantiene attivo il programma
while 1:
    time.sleep(10)

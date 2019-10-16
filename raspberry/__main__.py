# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File classe database
# È stato costruito da Alessandro Massarenti
# V 2.0

import time
import telepot
from telepot.loop import MessageLoop
import serial

from config import *
from telepot.namedtuple import ReplyKeyboardMarkup, KeyboardButton, ReplyKeyboardRemove

# Handle input
usb = "USB0"
serial = serial.Serial('/dev/tty'+usb, 9600)

def get_data():
    data = serial.readline().decode('utf8')
    print(data)
    data = data.split(' ')
    print(data)
    return data


def msg_handler(msg):

    content_type, chat_type, chat_id = telepot.glance(msg)
    user_id = msg['from']['id']

    if content_type == 'text':
        comando = msg['text']

        if(comando == 'avocado'):
            get_data


MessageLoop(bot, msg_handler).run_as_thread()
print('Listening ...')

# Mantiene attivo il programma
while 1:
    time.sleep(10)

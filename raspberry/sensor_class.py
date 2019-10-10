# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File classe database
# È stato costruito da Alessandro Massarenti
# V 2.0

import serial

class Sensor:

    def __init__(self, usb):
        self.serial = serial.Serial('/dev/tty'.usb, 9600)

    def get_data(self):
        data = self.serial.readline().decode('utf8')
        data = data.split(',')
        return data
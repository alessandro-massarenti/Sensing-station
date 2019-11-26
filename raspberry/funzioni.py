# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File file funzioni
# È stato costruito da Alessandro Massarenti
# V 2.0


def get_data(data_name: str, serial) -> float:
    to_be_written = data_name + "\n"
    print(serial.write(to_be_written.encode()))
    data = serial.readline().decode('utf8')
    data = data[4:]
    print(data)
    return float(data)

# -*- coding: utf-8 -*-

# Questo è readyhelp
# File principale
# È stato costruito da Alessandro Massarenti
# V 1.1

# inporta dipendenze interne

from config import *

db = connessione()


def read_data():
    c = db.cursor()
    sql = "SELECT id,temp,umid,time FROM dati ORDER BY id DESC LIMIT 1"
    c.execute(sql)
    data = c.fetchone()
    db.commit()
    print(data)
    return data


def send_data(chat_id):
    data = read_data()
    testo = "\nTemperatura: " + str(data[1]) + \
            "\nUmidità: " + str(data[2]) + \
            "\nMisurato alle: " + str(data[3])

    bot.sendMessage(chat_id, text=testo)

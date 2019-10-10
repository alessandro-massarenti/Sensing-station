# -*- coding: utf-8 -*-

# Questo è Sensorberry
# File classe database
# È stato costruito da Alessandro Massarenti
# V 2.0

import telepot
from telepot.loop import MessageLoop

class Bot:

    bot = telepot.Bot("Bot Token")

    def send_data(chat_id):
        data = read_data()
        testo = "\nTemperatura: " + str(data[1]) + \
                "\nUmidità: " + str(data[2]) + \
                "\nMisurato alle: " + str(data[3])

        bot.sendMessage(chat_id, text=testo)

    def on_chat_message(self, msg):
        content_type, chat_type, chat_id = telepot.glance(msg)
        user_id = msg['from']['id']
        print(content_type, chat_type, chat_id, user_id)

        if content_type == 'text':
            # Mette il messaggio come variabile
            comando = msg['text']
            if comando == "/data":
                send_data(chat_id)
# -*- coding: utf-8 -*-

# Questo è Sensorberry_b
# File principale
# È stato costruito da Alessandro Massarenti
# V 1.0


# Inporta dipendenze esterne
import time

from telepot.loop import MessageLoop

from funzioni import *


# inporta dipendenze interne


# Handle chat messages



# Fa andare l' ascolto degli imput come un thread separato.
MessageLoop(bot, {'chat': on_chat_message}).run_as_thread()
print('Listening ...')

# Mantiene attivo il programma
while 1:
    time.sleep(10)

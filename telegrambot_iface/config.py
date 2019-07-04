# -*- coding: utf-8 -*-

# Questo è readyhelp
# File principale
# È stato costruito da Alessandro Massarenti
# V 1.1
# Inporta dipendenze esterne
import telepot
import mysql.connector

# Bot token
bot = telepot.Bot("Bot Token")

# Database position
def connessione():
    db = mysql.connector.connect(
        host="localhost",
        user="datatest",
        passwd="cacconaZizzona",
        database="datatest"
    )
    return db

# Messaggio in GUI
print ("config.py caricato")
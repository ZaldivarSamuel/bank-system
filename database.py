import mysql.connector

class Database:

    def checkDatabase(self):
    
        mydb = mysql.connector.connect(
            host="localhost",
            user="root",
            password="ios9Coder1!"
        )

        mycursor = mydb.cursor()

        mycursor.execute("CREATE DATABASE bank")

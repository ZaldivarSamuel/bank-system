import mysql.connector
from mysqlx import OperationalError

class Database:

    connection = None

    def connect_to_database():
    
        Database.connection = mysql.connector.connect(
            host="localhost",
            user="root",
            password="ios9Coder1!"
        )
    
        if not Database.__check_if_database_exists():
            print("Database not found")
            Database.run_sql_file("sql/setup.sql")


    def run_sql_file(file):
        cur = Database.connection.cursor()
        with open(file, 'r') as sql_file:
            cur.execute(sql_file.read(), multi=True)


    def __check_if_database_exists():
    
        cursor = Database.connection.cursor()
        cursor.execute("SHOW DATABASES")

        for x in cursor:
            if x[0] == "bank":
                return True
        
        return False
#include "database.h"
#include <iostream>

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

/*
Database class constructor.
Open bank database and create tables if neccesary
*/
Database::Database(){
    rc = sqlite3_open("bank.db", &db);

    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(1);
   } else {
      fprintf(stderr, "Opened database successfully\n");
      //TODO: Check if tables are already created in database
      createTables();
   }
}

/*
Create a new bank account.
Each account will have an ID and the amount saved in the account.
*/
void Database::createAccount(){
   char const *sql = "INSERT INTO Accounts (Amount) VALUES(0.00);";
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
}



void Database::createTables(){
    std::cout << "Creating Tables" << std::endl;

    char const *sql = "CREATE TABLE Accounts("  \
      "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
      "Amount           DOUBLE    NOT NULL );";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
}


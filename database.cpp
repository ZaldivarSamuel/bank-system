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


Database::Database(){
    rc = sqlite3_open("bank.db", &db);

    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(1);
   } else {
      fprintf(stderr, "Opened database successfully\n");
      createTables();
   }
}

void Database::createTables(){
    std::cout << "Creating Tables" << std::endl;

    char const *sql = "CREATE TABLE Accounts("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "Amount           DOUBLE    NOT NULL );";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
}


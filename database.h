#include <sqlite3.h>

class Database{

public:
    sqlite3 *db;
    int rc;

    Database();

private:
     char *zErrMsg = 0;
    void createTables();
   // int callback(void *data, int argc, char **argv, char **azColName);
};
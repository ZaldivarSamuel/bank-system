#include <sqlite3.h>

class Database{

public:
    
    Database();
    void createAccount();

private:
    sqlite3 *db;
    int rc;
    char *zErrMsg = 0;
    void createTables();
};
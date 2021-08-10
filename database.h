#include <sqlite3.h>

using namespace std;

class Database{

public:
    sqlite3 *db;
    int rc;


    Database();
};
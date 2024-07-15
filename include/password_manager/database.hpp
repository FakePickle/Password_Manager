#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <sqlite3.h>
#include <cstring>
#include <iostream>

using namespace std;

class Database {
public:
    Database(const std::string& db_name);
    ~Database();

    bool executeQuery(const std::string& query);
    bool initializeDatabase();
    string getPassword(const string& key);
    void printPasswords();

private:
    sqlite3* db;
};

#endif // DATABASE_HPP

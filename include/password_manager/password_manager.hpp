#ifndef PASSWORD_MANAGER_HPP
#define PASSWORD_MANAGER_HPP

#include <string>
#include "database.hpp"
#include "encryption.hpp"
#include <openssl/sha.h>
#include <iostream>
#include <sqlite3.h>

class PasswordManager {
public:
    PasswordManager(const string& db_name, const string& master_password);
    ~PasswordManager();

    void addPassword(const string& key, const string& password);
    void generatePassword(size_t length, const string& key);
    void removePassword(const string& key);
    string getPassword(const string& key);
    void printPasswords();

private:
    string masterPasswordHash;
    Database db;

    string hashMasterPassword(const string& master_password);
};

#endif // PASSWORD_MANAGER_HPP

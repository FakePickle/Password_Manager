#include <password_manager/database.hpp>
#include <password_manager/encryption.hpp>

Database::Database(const string& db_name) {
    if (sqlite3_open(db_name.c_str(), &db)) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
    } else {
        initializeDatabase();
    }
}

Database::~Database() {
    sqlite3_close(db);
}

bool Database::executeQuery(const string& query) {
    char* errMsg = 0;
    if (sqlite3_exec(db, query.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::initializeDatabase() {
    string createTableQuery = "CREATE TABLE IF NOT EXISTS passwords (key TEXT PRIMARY KEY, password TEXT);";
    return executeQuery(createTableQuery);
}

string Database::getPassword(const string& key) {
    string query = "SELECT password FROM passwords WHERE key='" + key + "';";
    sqlite3_stmt* stmt;
    string password;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        }
        sqlite3_finalize(stmt);
    }
    return password;
}

void Database::printPasswords() {
    string query = "SELECT key, password FROM passwords;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            string key = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            string password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            cout << "Key: " << key << ", Password: " << password << endl;
        }
        sqlite3_finalize(stmt);
    }
}

#include <password_manager/password_manager.hpp>
#include <password_manager/encryption.hpp>
#include <password_manager/database.hpp>

PasswordManager::PasswordManager(const string& db_name, const string& master_password)
    : db(db_name), masterPasswordHash(hashMasterPassword(master_password)) {
    db.initializeDatabase();
}

PasswordManager::~PasswordManager() {}

void PasswordManager::addPassword(const string& key, const string& password) {
    string encryptedPassword = encrypt(password, masterPasswordHash);
    string query = "INSERT INTO passwords (key, password) VALUES ('" + key + "', '" + encryptedPassword + "');";
    db.executeQuery(query);
}

void PasswordManager::removePassword(const string& key) {
    string query = "DELETE FROM passwords WHERE key='" + key + "';";
    db.executeQuery(query);
}

string PasswordManager::getPassword(const string& key) {
    string encryptedPassword = db.getPassword(key);
    return decrypt(encryptedPassword, masterPasswordHash);
}

void PasswordManager::printPasswords() {
    db.printPasswords();
}

void PasswordManager::generatePassword(size_t length, const string& key) {
    string lowCase = "abcdefghijklmnopqrstuvwxyz";
    string upCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    string password = "";
    for (int i = 0; i < length; i++) {
        int choice = rand() % 4;
        switch (choice) {
        case 0:
            password += lowCase[rand() % lowCase.length()];
            break;
        case 1:
            password += upCase[rand() % upCase.length()];
            break;
        case 2:
            password += numbers[rand() % numbers.length()];
            break;
        case 3:
            password += special[rand() % special.length()];
            break;
        }
    }

    cout << "Generated password: " << password << endl;
    cout << "Do you want to save it? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        addPassword(key, password);
    }
    else {
        cout << "Password not saved." << endl;
    }
}

string PasswordManager::hashMasterPassword(const string& master_password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(master_password.c_str()), master_password.length(), hash);
    
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << static_cast<unsigned int>(hash[i]);
    }
    return ss.str();
}

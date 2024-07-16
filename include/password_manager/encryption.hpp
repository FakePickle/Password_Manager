#ifndef PASSWORD_MANAGER_ENCRYPTION_HPP
#define PASSWORD_MANAGER_ENCRYPTION_HPP

using namespace std;

#include <string>
#include "password_manager.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

string encrypt(const string& plaintext, const string& key);
string decrypt(const string& ciphertext, const string& key);

#endif
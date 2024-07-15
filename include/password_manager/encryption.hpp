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

std::string encrypt(const std::string& plaintext, const std::string& key);
std::string decrypt(const std::string& ciphertext, const std::string& key);

#endif
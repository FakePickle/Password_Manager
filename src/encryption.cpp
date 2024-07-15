#include <password_manager/encryption.hpp>
#include <iostream>
#include <cstring>
#include <openssl/evp.h>
#include <vector>

string encrypt(const string& plaintext, const string& key) {
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);
    
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key.c_str(), iv);
    
    vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);
    int len;
    EVP_EncryptUpdate(ctx, ciphertext.data(), &len, (unsigned char*)plaintext.c_str(), plaintext.size());
    
    int ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len);
    ciphertext_len += len;
    
    EVP_CIPHER_CTX_free(ctx);

    string result((char*)iv, AES_BLOCK_SIZE);
    result += string((char*)ciphertext.data(), ciphertext_len);
    return result;
}

string decrypt(const string& ciphertext, const string& key) {
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, ciphertext.c_str(), AES_BLOCK_SIZE);
    
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key.c_str(), iv);
    
    vector<unsigned char> plaintext(ciphertext.size());
    int len;
    EVP_DecryptUpdate(ctx, plaintext.data(), &len, (unsigned char*)ciphertext.c_str() + AES_BLOCK_SIZE, ciphertext.size() - AES_BLOCK_SIZE);
    
    int plaintext_len = len;
    EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len);
    plaintext_len += len;
    
    EVP_CIPHER_CTX_free(ctx);
    return string((char*)plaintext.data(), plaintext_len);
}

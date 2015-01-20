#ifndef CRYPTO_2_HPP_INCLUDED
#define CRYPTO_2_HPP_INCLUDED

#include <string>

namespace cryptoLib2 {
    extern const std::string ALPHABET;

    bool is_valid_key(std::string k);

    bool is_valid_cleartext(const std::string &s);

    int char_index(char c);

    std::string encrypt(std::string message, const std::string &key);
}

std::string find_key(std::string plaintext, std::string cyphertext);

#endif  // CRYPTO_2_HPP_INCLUDED

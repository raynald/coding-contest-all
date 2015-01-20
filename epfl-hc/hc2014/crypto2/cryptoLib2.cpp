#include "cryptoLib2.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;
using namespace cryptoLib2;

namespace cryptoLib2 {
    const string ALPHABET = "_abcdefghijklmnopqrstuvwxyz";

    bool is_valid_key(string k) {
        sort(k.begin(), k.end());
        string alphabet = ALPHABET;
        sort(alphabet.begin(), alphabet.end());
        return k == alphabet;
    }

    bool is_valid_cleartext(const string &s) {
        for (string::const_iterator i = s.begin(), e = s.end(); i != e; ++i) {
            if (*i != '_' && !(*i >= 'a' && *i <= 'z')) return false;
        }
        for (string::const_iterator i = ALPHABET.begin(), e = ALPHABET.end(); i != e; ++i) {
            if (s.find(*i) == string::npos) return false;
        }

        return true;
    }

    int char_index(char c) {
        return (c == '_') ? 0 : c - 'a' + 1;
    }

    string encrypt(string message, const string &key) {
        for (string::iterator i = message.begin(), e = message.end(); i != e; ++i) {
            *i = key[char_index(*i)];
        }
        return message;
    }
}

int main() {

    string line;
    while (getline(cin, line)) {
        if (line == "") continue;

        string cleartext = line;
        string cyphertext;
        getline(cin, cyphertext);

        assert(cleartext.size() == cyphertext.size() && "Cleartext must match cyphertext");
        assert(is_valid_cleartext(cleartext) && "Invalid cleartext in input file");
        assert(is_valid_cleartext(cyphertext) && "Invalid cyphertext in input file");

        string key = find_key(cleartext, cyphertext);
        if (!is_valid_key(key)) {
            cout << "Incorrect\n";
            return 1;
        }
        if (cyphertext != encrypt(encrypt(cleartext, key), key)) {
            cout << "Incorrect\n";
            return 1;
        }
    }

    cout << "Looks pretty good" << endl;
    return 0;
}

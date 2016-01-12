/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <iostream>
#include <string>
using namespace std;

#include "cryptoLib3.hpp"

void answer(string message) {
  cout << message << endl;
}

int main() {
  string cipher;
  cin >> cipher;
  crypto(cipher);
}

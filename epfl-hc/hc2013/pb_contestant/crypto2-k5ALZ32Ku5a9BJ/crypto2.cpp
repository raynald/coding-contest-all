#include "cryptoLib2.hpp"

/*
   THIS IS THE ONLY FILE YOU SHOULD SUBMIT
*/
int decrypt(int ciphertext, int key1, int key2) {
  int pt;
  for(pt = 0; pt < 65536; ++pt) {
    if(encrypt(pt, key1, key2) == ciphertext) {
      return pt;
    }
  }
  return 0;
}

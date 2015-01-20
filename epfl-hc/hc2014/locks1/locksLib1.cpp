/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include "locksLib1.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string ans;

int login(const char * password) {
  if(password == ans) {
    return -1;
  }

  int time = 0;
  for(string::iterator c = ans.begin(); *password != 0 && c != ans.end(); c++, password++) {
    if(*password != *c) {
      break;
    }

    time += 30 + rand() % 3;
  }

  return time;
}

int main() {
  srand(time(NULL));
  cin >> ans;
  timing();
}

void answer(string a) {
  cout << a << endl;
}

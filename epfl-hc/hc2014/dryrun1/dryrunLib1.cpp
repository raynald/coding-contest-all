/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include "dryrunLib1.hpp"
#include <iostream>

using namespace std;

int main(){
  int a,b,contestantSolution;
  cin >> a >> b;
  contestantSolution = mysteriousOperator(a,b);
  if (contestantSolution == b*(a%b))
    cout << "Correct" << endl;
  else  
    cout << "Wrong" << endl;
  return 0;
}

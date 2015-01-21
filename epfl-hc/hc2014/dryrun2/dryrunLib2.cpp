/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include "dryrunLib2.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

int n, numTrials = 0;

int isIt(int a){
  numTrials++;
  if (a<n) return TOO_LOW;
  if (a>n) return TOO_HIGH;
  return YES;
}

int main(){
  cin >> n;
  if (guessNumber() == n && numTrials <= 7)
    printf("Correct\n");
  else
    printf("Wrong\n");
}

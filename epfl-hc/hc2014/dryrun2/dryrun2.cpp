///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include "dryrunLib2.hpp"

int guessNumber(){
  // your code goes here...
  int left = 1;
  int right = 100;
  int mid;
  while(left <= right) {
      mid = (left+right)/2;
      int temp = isIt(mid);
      if(temp==TOO_LOW) {
          left = mid + 1;
      } else if(temp==TOO_HIGH) {
          right= mid - 1;
      } else return mid;
  }
  return 0;
}

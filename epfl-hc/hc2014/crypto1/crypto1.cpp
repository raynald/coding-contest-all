//////////////////////
// SUBMIT THIS FILE //
//////////////////////

#include "cryptoLib1.hpp"
#include<cmath>

bool is_password_correct(int password) {
    int n = password;
    int times = 0;
    for(int i=2;i<=sqrt(password);i++) {
        if(n==1) break;
        while(n%i==0) {
            n/=i;
            times++;
        }
    }
    if(n>1) times++;
    if(times==1) return 0;
    for(int i=2;i<=sqrt(times);i++) {
        if(times%i==0) return 0;
    }
    return 1;
}

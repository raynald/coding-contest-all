///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include "cyberfoodLib2.hpp"
#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

long long int estimate_flavours(int S){
    long long int t;
    long long int ans=0;
    for(int i=0;i<S;i++) {
        t = eat();
        if(t>ans) ans =t;
    }
	return ans*(S+1.0)/S; 
}


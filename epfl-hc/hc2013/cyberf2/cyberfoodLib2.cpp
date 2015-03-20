/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<cmath>
#include<iostream>
#include"cyberfoodLib2.hpp"
using namespace std;

static long long int solJudge, solTeam;
static int nSamples;
static int score(0);

long long int eat(){
	if (!nSamples){
		printf("Too many samples\n");
		exit(0);
	 }
	 nSamples--;
	 return 1+rand()%solJudge;
}

int main() {
	int T;
	double tol;
	assert(scanf("%d",&T)==1);
	for (int i=0; i<T; i++){
		assert(scanf("%lld %lf",&solJudge,&tol)==2);
		nSamples = ceil( log(1/(1-0.95)) / log(0.01*tol+1) );
		solTeam = estimate_flavours(nSamples);
		score += max(solTeam,solJudge)-min(solTeam,solJudge) <= tol*solJudge*0.01;
	}
	if ( score/(0.01*T) >= 95.00 ) {
		printf("CORRECT\n");
        } else {
                printf("Solved %.3lf%% of tests\n", score/(0.01*T));
		printf("INCORRECT\n");
        }
	return 0;
}

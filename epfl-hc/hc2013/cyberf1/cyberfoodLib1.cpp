/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"cyberfoodLib1.hpp"
using namespace std;

static int L, C;

static inline long long int bijective_encrypt(long long int x){
	// the judge will perform some fency encryption here
	return x;
}

static inline long long int bijective_decrypt(long long int x){
	// the judge will reverse its fency encrytion here
	return x;
}

long long int eat(long long int prev){
	prev = bijective_decrypt(prev);
	if (prev<1ll*L)
		prev++;
	else
		prev = (prev+1-L)%C + L;
	return bijective_encrypt(prev);
}

int main(){
	int T;
	int solTeam, solJudge;
	assert(scanf("%d",&T)==1);
	for (int i=0; i<T; i++){
		assert(scanf("%d %d",&L,&C)==2);
		solTeam = count_flavours(bijective_encrypt(1ll));
		solJudge = L+C-1;
		if (solTeam != solJudge){
			printf("INCORRECT - test %d received %d / expected %d\n",i+1,solTeam,solJudge);
			exit(0);
		}
	}
	printf("CORRECT\n");
	return 0;
}

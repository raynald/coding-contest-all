/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"cyberspaceLib2.hpp"
using namespace std;

int main() {
	int T;
	int N, M;
	int solJudge, solTeam;
	assert(scanf("%d",&T)==1);
	for (int i=0; i<T; i++){
		assert(scanf("%d %d %d",&N,&M,&solJudge)==3);
		solTeam = place_exit(N,M);
		if (solTeam != solJudge){
			printf("INCORRECT - test %d received %d / expected %d\n",i+1,solTeam,solJudge);
			exit(0);
		}
	}
	printf("CORRECT\n");
	return 0;
}

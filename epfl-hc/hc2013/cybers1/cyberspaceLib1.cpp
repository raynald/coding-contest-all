/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"cyberspaceLib1.hpp"
using namespace std;

#define MAX_N 1000001

int main(){
	int T;
	int solTeam, solJudge;
	int a[MAX_N], p[MAX_N];
	int N;
	assert(scanf("%d",&T)==1);
	for (int i=0; i<T; i++){
		assert(scanf("%d",&N)==1);
		for (int j=0; j<=N; j++)
			assert(scanf("%d %d",&a[j],&p[j])==2);
		assert(scanf("%d",&solJudge));
		solTeam = entry_time(a,p,N);
		if (solTeam != solJudge){
			printf("INCORRECT - test %d received %d / expected %d\n",i+1,solTeam,solJudge);
			exit(0);
		}
	}
	printf("CORRECT\n");
	return 0;
}

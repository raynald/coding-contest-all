/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include"quarantineLib2.hpp"
using namespace std;

#define MAXN 1000

static int pp[MAXN][MAXN];
static bool p[MAXN][MAXN];

static void read_picture(int N){
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++){
			assert(scanf("%d",&pp[i][j])==1);
			p[i][j] = pp[i][j];
		}
}

int main(){
	srand(time(NULL));
	int T, Q, r1, c1, r2, c2;
	int N;
	int solTeam, solJudge;
	assert(scanf("%d",&T)==1);
	for (int i=0; i<T; i++){
		assert(scanf("%d",&N)==1);
		read_picture(N);
		load_picture(p,N);
		assert(scanf("%d",&Q)==1);
		for (int j=0; j<Q; j++){
			assert(scanf("%d %d %d %d %d",&r1,&c1,&r2,&c2,&solJudge)==5);
			solTeam = query(r1,c1,r2,c2);
			if (solTeam != solJudge){
				printf("INCORRECT - picture %d query %d received %d / expected %d\n",i+1,j+1,solTeam,solJudge);
				exit(0);
			}
		}
	}
	printf("CORRECT\n");
	return 0;
}

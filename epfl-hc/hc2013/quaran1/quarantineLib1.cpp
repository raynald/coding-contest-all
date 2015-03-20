/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#undef NDEBUG
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include"quarantineLib1.hpp"
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
	int T, Q, r, c;
	int N;
	int solTeam, solJudge;
	assert(scanf("%d",&T)==1);
	for (int i=0; i<T; i++){
		assert(scanf("%d",&N)==1);
		read_picture(N);
		load_picture(p,N);
		assert(scanf("%d",&Q)==1);
		for (int j=0; j<Q; j++){
			assert(scanf("%d %d %d",&r,&c,&solJudge)==3);
			solTeam = query(r,c);
			if (solTeam != solJudge){
				printf("INCORRECT - picture %d query %d received %d / expected %d\n",i+1,j+1,solTeam,solJudge);
				exit(0);
			}
		}
	}
	printf("CORRECT\n");
	return 0;
}

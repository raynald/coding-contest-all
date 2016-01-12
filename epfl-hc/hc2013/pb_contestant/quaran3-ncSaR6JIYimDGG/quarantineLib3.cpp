/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include"quarantineLib3.hpp"
using namespace std;

#define MAXN 1000

int main(){
	srand(time(NULL));
	int T, Q, r1, c1, r2, c2;
	int N;
	int solTeam, solJudge;
	int cnt;
	char op;
	assert(scanf("%d",&T)==1);
	for (int i=0; i<T; i++){
		cnt=0;
		assert(scanf("%d",&N)==1);
		load_picture(N);
		assert(scanf("%d",&Q)==1);
		for (int j=0; j<Q; j++){
			assert(scanf("%c%c",&op,&op)==2);
			if (op=='T'){
				assert(scanf("%d %d %d %d",&r1,&c1,&r2,&c2)==4);
				toggle(r1,c1,r2,c2);
			}
			else{
				cnt++;
				assert(scanf("%d %d %d",&r1,&c1,&solJudge)==3);
				solTeam = query(r1,c1);
				if (solTeam != solJudge){
					printf("INCORRECT - picture %d query %d received %d / expected %d\n",i+1,cnt,solTeam,solJudge);
					exit(0);
				}
			}
		}
	}
	printf("CORRECT\n");
	return 0;
}

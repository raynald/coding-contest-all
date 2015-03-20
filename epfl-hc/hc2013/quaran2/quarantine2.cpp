///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include"quarantineLib2.hpp"
#include<cstring>

int dp[1001][1001];

void load_picture(bool p[1000][1000], int N){
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j]-dp[i][j] + p[i][j];
        }
    }
}

bool query(int r1, int c1, int r2, int c2){
	return dp[r2+1][c2+1] - (dp[r1][c2+1] + dp[r2+1][c1] - dp[r1][c1]) > (r2-r1+1)*(c2-c1+1) /2;
}


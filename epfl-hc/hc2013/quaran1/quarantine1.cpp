///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include"quarantineLib1.hpp"
#include<cstring>

int row[1000];
int col[1000];
int Now;
bool pixel[1000][1000];

void load_picture(bool p[1000][1000], int N){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    Now = N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            pixel[i][j] = p[i][j];
            if(p[i][j]) {
                row[i] ++;
                col[j] ++;
            }
        }
    }
}

bool query(int r, int c){
    if(row[r] > Now / 2 && col[c] > Now/2) return 1;
    if(row[r]+ col[c] -pixel[r][c] >= Now) return 1;
    return 0;
}


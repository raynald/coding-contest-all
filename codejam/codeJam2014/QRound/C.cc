#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

int main() {
    int T;
    bool flag;
    int R, C, M;
    int c;
    char mat[51][51];
    char tmp;
    int mr, mc;

    cin >> T;
    for(int k=1;k<=T;k++) {
        flag = true;
        c = 0;
        cin >> R >> C >> M;
        if((R*C-M)%R%2==0 && (R*C-M)/R>=2) {
            for(int j=0;j<C;j++) {
                for(int i=0;i<R;i++) {
                    c++;
                    if(c<=M) mat[i][j] = '*';
                    else mat[i][j] = '.';
                }
            }
            mat[R-1][C-1] = 'c';
        }
        else {
            if((R*C-M)%C%2 ==0 && (R*C-M)/C>=2) {
                for(int i=0;i<R;i++) {
                    for(int j=0;j<C;j++) {
                        c++;
                        if(c<=M) mat[i][j] = '*';
                        else mat[i][j] = '.';
                    }
                }
                mat[R-1][C-1] = 'c';
            }
            else {
                if(R*C-M==4) {
                    for(int i=0;i<R;i++) {
                        for(int j=0;j<C;j++) {
                            mat[i][j] = '*';
                        }
                    }
                    mat[0][0]='c';
                    mat[0][1]='.';
                    mat[1][1]='.';
                    mat[1][0]='.';
                }
                else {
                    if(R-C-M==1) {
                        for(int i=0;i<R;i++) {
                            for(int j=0;j<C;j++) {
                                mat[i][j] = '*';
                            }
                        }
                        mat[0][0] = 'c';
                    }
                    else {
                        flag = false;
                    }
                }
            }
        }
        cout << "Case #" << k << ":\n";
        if(flag) {
            for(int i=0;i<R;i++) {
                for(int j=0;j<C;j++) {
                    cout << mat[i][j];
                }
                cout << endl;
            }
        }
        else {
            cout << "Impossible\n";
        }
    }
    return 0;
}


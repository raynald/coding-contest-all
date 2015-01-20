#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

int T;
int x;
int minx, maxx;
int N;
int NN;
int a[11];
int b[11];
int c[11];
bool flag;


bool comp(int u[], int v[]) {
    if(u[x-1] == 0) return 0;
    for(int i=x-1;i>=0;i--) {
        if(u[i]<v[i]) return 1;
        if(u[i]>v[i]) return 0;
    }
    return 0;
}

int main() {
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> NN;
        cout << "Case #" << i+1 << ": ";
        if(NN==0) {
            cout << 0 << " " << 0 << endl;
        } else {
            N = NN;
            x = 0;
            while(N!=0) {
                a[x++] = N%10;
                N/=10;
            }
            memcpy(b, a, sizeof(a));
            memcpy(c, a, sizeof(a));
            flag = 0;
            for(int j=x-1;j>=1;j--) {
                for(int k=0;k<=j-1;k++) {
                    swap(a[j], a[k]);
                    if(comp(a,b)) {
                        memcpy(b, a, sizeof(a));
                    }
                    swap(a[j],a[k]);
                }
            }
            for(int j=x-1;j>=0;j--) cout << b[j];
            cout << " ";
            flag = 0;
            for(int j=x-1;j>=1;j--) {
                for(int k=j-1;k>=0;k--) {
                    swap(a[j], a[k]);
                    if(comp(c,a)) {
                        memcpy(c,a,sizeof(a));
                    }
                    swap(a[j], a[k]);
                }
            }
            for(int j=x-1;j>=0;j--) cout << c[j];
            cout << endl;
        }
    }
    return 0;
}

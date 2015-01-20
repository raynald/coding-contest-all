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

vector<int> mat[1010];
bool v[1010];

int dfs(int x) {
    int a, b, tmp;

    v[x]=1;
    a = b = 0;
    for(int j=0;j<mat[x].size();j++) {
        if(!v[mat[x][j]]) {
            tmp = dfs(mat[x][j]);
            if(tmp>a) {
                b = a;
                a = tmp;
            }
            else {
                if(tmp>b) {
                    b = tmp;
                }
            }
        }
    }
    if(b==0) return 1; else return 1+a+b;
}

int main() {
    int T;
    int N;
    int a,b;
    int tmp;
    int ans;
    
    cin >> T;
    for(int i=1;i<=T;i++) {
        cin >> N;
        ans = N;
        for(int j=0;j<=N;j++) mat[j].clear();
        for(int j=1;j<N;j++) {
            cin >> a >> b;
            a--;b--;
            mat[a].push_back(b);
            mat[b].push_back(a);
        }
        for(int j=0;j<N;j++) {
            memset(v,0,sizeof(v));
            tmp = dfs(j);
            //cout << j << " " << tmp<<endl;
            if(N-tmp<ans) ans = N-tmp;
        }
        cout << "Case #" << i <<": "<< ans<< endl;
    }

    return 0;
}


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

const int MAXH = 1000000007;
struct cmp {
    int x;
    int y;
    cmp () {x = 0, y = 0;}
    cmp(int u, int v):x(u), y(v) {}
};

bool comp(const cmp &u, const cmp &v) {
    return u.x<v.x || u.x==v.x && u.y<v.y;
}

long long fact(long long y, long long x) {
    long long sum = y;

    for(int i=1;i<=x;i++) {
        sum = (sum*i)%MAXH;
    }
    return sum;
}
string str;
long long multi;
string s[110];
cmp car[110];
cmp tmp;
bool v[26];
bool flag;
cmp mat[26];
bool d[26];
int ans;
int rep, N;

bool dfs(int x, bool y) {
    if(x==-1) return 1;
    if(v[x]) return 0;
    v[x] = 1;
    if(y==0) return mat[x].x==x || dfs(mat[x].x, 0); else return mat[x].y == x || dfs(mat[x].y, 1);
}

bool check() {
    for(int i=0;i<N;i++) {
        for(int j=1;j<s[i].length()-1;j++) {
            for(int u=0;u<N;u++) {
                if(u==i) continue;
                for(int l=0;l<s[u].length();l++) {
                    if(s[i][j]==s[u][l]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int T;

    cin >> T;
    for(int k=1;k<=T;k++) {
        cin >> N;
        flag = 1;
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        cout << "Case #" << k << ": ";
        for(int i=0;i<26;i++) mat[i] = cmp(-1,-1);
        for(int i=0;i<N;i++) {
            cin >> str;
            s[i] = str[0];
            for(int j=1;j<str.length();j++) {
                if(str[j]!=str[j-1]) s[i]+=str[j]; 
            }
            for(int j=0;j<s[i].length();j++) {
                for(int k=j+1;k<s[i].length();k++) {
                    if(s[i][j]==s[i][k]) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if(flag) {
            if(check()) {
                for(int i=0;i<N;i++) {
                    car[i] = cmp(s[i][0]-'a',s[i][s[i].length()-1]-'a');
                }
                multi = 1;
                sort(car,car+N,comp);
                tmp = car[0];
                mat[tmp.x].y=tmp.y;
                d[tmp.x]++;
                mat[tmp.y].x=tmp.x;
                rep=1;
                for(int i=1;i<N;i++) {
                    if(car[i].x==tmp.x && car[i].y==tmp.y) {
                        if(tmp.x!=tmp.y) {
                            flag = 0;
                            break;
                        }
                        rep++;
                    }
                    else {
                        multi=fact(multi, rep);
                        rep = 1;
                        tmp=car[i];
                        if(d[tmp.x]==1) {
                            if(mat[tmp.x].y == -1 || mat[tmp.x].y==tmp.x) mat[tmp.x].y= tmp.y;
                            else if(tmp.x!=tmp.y) {
                                flag = 0;
                                break;
                            }
                            if(mat[tmp.y].x == -1 ||mat[tmp.y].x==tmp.y) mat[tmp.y].x= tmp.x;
                        }
                        else {
                            if(mat[tmp.y].y == tmp.x) {
                                flag = 0;
                                break;
                            }
                            mat[tmp.x].y=tmp.y;
                            if(mat[tmp.y].x==-1 || mat[tmp.y].x == tmp.y) mat[tmp.y].x=tmp.x;
                            d[tmp.x]++;
                        }
                    }
                }
                if(flag) {
                    if(rep>1) {
                        multi = fact(multi, rep);
                        rep = 1;
                    }
                    ans = 0;
                    for(int i=0;i<26;i++) {
                        if(!v[i] && d[i]>0) {
                            v[i] = 0;
                            if(mat[i].x!=i) flag = flag && dfs(mat[i].x, 0);
                            if(mat[i].y!=i) flag = flag && dfs(mat[i].y, 1);
                            if(!flag) break;
                            ans++;
                        }
                    }
                    multi = fact(multi, ans);
                }
            }
            else flag = 0;
        }
        if(!flag) cout << 0 << endl;
        else cout << multi << endl;
    }

    return 0;
}


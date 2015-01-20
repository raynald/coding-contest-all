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

const int MAXN  = int(1e7+10);
bool flag;
vector<int> prime;
int f[MAXN][9];

int main() {
    int T;
    int num;
    int count;
    int ans;
    int A, B, K;
    
    prime.clear();
    for(int i=2;i<=sqrt(1e7);i++) {
        flag = 1;
        for(int j=0;j<prime.size();j++) {
            if(i%prime[j]==0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            prime.push_back(i);
        }
    }
    memset(f,0,sizeof(f));
    for(int i=2;i<=int(1e7);i++) {
        num = i;
        count = 0;
        for(int j=0;j<prime.size();j++) {
            if(num<prime[j]) break;
            if(num%prime[j]==0) {
                while(num%prime[j]==0) {
                    num/=prime[j];
                }
                count++;
            }
        }
        if(num>1) count++;
        for(int j=1;j<=8;j++) f[i][j] = f[i-1][j];
        f[i][count] ++;
    }
    cin >> T;
    for(int testcase = 1; testcase <= T; testcase++) {
        cin >> A >> B >> K;
        if(K<=8) {
            ans = f[B][K] - f[A-1][K];
        } else ans = 0;
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}

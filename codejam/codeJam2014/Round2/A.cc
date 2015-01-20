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

int s[10010];

int main() {
    int T;
    int ans;
    int l, r;
    int N, C;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> N >> C;
        for(int i=0;i<N;i++) 
            cin >> s[i];
        sort(s, s+N);
        l = 0; r = N-1;
        ans = 0;
        while(l<=r) {
            if(l==r || s[l]+s[r]<=C) {
                l++;
                r--;
                ans++;
            }
            else {
                r--;
                ans++;
            }
        }
        cout << "Case #" << t << ": ";
        cout << ans << endl;
    }
    return 0;
}

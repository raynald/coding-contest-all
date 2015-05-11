#include<iostream>
#include<vector>

using namespace std;

int ans;
int now;
int D;
int T;
int p[1010];

void init() {
    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> D;
        ans = 0;
        for(int i=0;i<D;i++) {
            cin >> p[i];
            if(p[i]>ans) ans = p[i];
        }
        for(int i=1;i<=1000;i++) {
            now = i;
            for(int j=0;j<D;j++) {
                if(p[j]>i) {
                    if(p[j]%i==0) now += p[j]/i-1; else now += p[j]/i;
                }
            }
            if(now<ans) ans = now;
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }
}

int main() {
    init();
}


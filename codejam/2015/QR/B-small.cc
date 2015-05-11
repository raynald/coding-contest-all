#include<iostream>
#include<vector>

using namespace std;

int ans;
int now;
int D;
int T;
int p[10];

void init() {
    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> D;
        ans = 0;
        for(int i=0;i<D;i++) {
            cin >> p[i];
            if(p[i]>ans) ans = p[i];
        }
        for(int i=1;i<=9;i++) {
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


// 1 1 1 1 1 = 1
// 2 2 2 2 2 = 2
// 3 3 3 3 3 = 3
// 4 2 2 2 2 = 3
// 4 3 = 4
// 5 <=3 = 4
// 5 4 = 5
// 6 3 = 4
// 6 4 = 5
// 6 5 = 6
// 7 4 = 5
// 7 5 = 6
// 7 6 = 7
// 8 4 = 5
// 8 5 = 6
// 8 6 = 7
// 8 7 = 8
// 9 3 = 5
// 9 5 = 6
// 9 9 5 = 7
// 9 9 6 = 8
// 9 9 7 7 = 8
// 9 9 9 5 = 8
// 9 9 9 6 = 9

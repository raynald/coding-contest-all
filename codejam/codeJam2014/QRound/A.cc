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

int main() {
    int T;
    int count;
    int a, b, tmp;
    int ans;
    map<int, bool> mmap;
    map<int, bool>::iterator got;

    cin >> T;
    for(int k=1;k<=T;k++) {
        cin >> a;
        mmap.clear();
        count = 0;
        for(int i = 1;i <= 4;i++)
            for(int j = 1;j <= 4;j++) {
                cin >> tmp;
                if(i==a) {
                    mmap.insert(pair<int, bool>(tmp, 1));
                }
            }
        cin >> b;
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++) {
                cin >> tmp;
                if(i==b) {
                    got = mmap.find(tmp);
                    if(got!=mmap.end()) {
                        ans = tmp;
                        count++;
                    }
                }
            }
        cout << "Case #" << k << ": ";
        switch(count) {
            case 0: cout << "Volunteer cheated!"<< endl; break;
            case 1: cout << ans << endl; break;
            default: cout << "Bad magician!" << endl; break;
        }
    }
    return 0;
}

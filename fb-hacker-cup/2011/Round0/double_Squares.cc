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
    int N;  
    int x;
    int t;
    int ans;
    cin >> N;
    for(int j=1;j<=N;j++) {
        cin >> x;
        ans = 0;
        for(int i=0;i<=sqrt(x/2);i++) {
            t = static_cast<int>(sqrt(x-i*i));
            if(t*t+i*i==x) ans++;
        }
        cout << "Case #" << j << ": " << ans << endl;
    }

    return 0;
}

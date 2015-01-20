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
    int T, N;
    int a[1010];
    int ans;
    int l, r;
    int min, minj;

    cin>>T;
    for(int t=1;t<=T;t++) {
        cin >> N;
        for(int i=0;i<N;i++) cin >> a[i];
        l = 0;
        r = N-1;
        ans = 0;
        while(l<r) {
            min = (int)2e10;
            for(int i = l;i<=r;i++) {
                if(a[i]<min) {
                    min = a[i];
                    minj = i;
                }
            }
            if(r-minj>minj-l) {
                ans+=minj-l;
                for(int i=minj;i>l;i--) {
                    swap(a[i],a[i-1]);
                }
                l++;
            }
            else {
                ans+=r-minj;
                for(int i=minj;i<r;i++) {
                    swap(a[i],a[i+1]);
                }
                r--;
            }
        }
        cout << "Case #" << t << ": ";
        cout << ans << endl;
    }
    return 0;
}


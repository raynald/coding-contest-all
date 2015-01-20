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
    int T;
    long long A, B, K;

    cin >> T;
    for(int k = 1;k <= T;k ++) {
        cin >> A >> B >> K;
        if(A>B) swap(A,B);
        if(K>=A) ans = A*B;
        else {
            :wq
        }
        cout << "Case #" << k << ": ";
    }

    return 0;
}

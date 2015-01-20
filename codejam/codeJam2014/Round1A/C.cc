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
    int T, N, G;
    int a, sum;

    cin >> T;
    for(int k=1;k<=T;k++) {
        cin >> N;
        sum = 0;
        for(int i=0;i<N;i++) {
            cin >> a;
            if(a<=i) sum++;
        }
        cout << "Case #" << k << ": ";
        if(sum<(472+500)/2) 
            puts("BAD"); 
        else 
            puts("GOOD");
    }
    return 0;
}


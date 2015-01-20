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
    double C, F, X;
    double cur;
    double time;
    double tmp;

    cin >> T;
    for(int k=1;k<=T;k++) {
        cin >> C >> F >> X;
        cur = 2;
        time = 0;
        while(X/cur >= C/cur+X/(cur+F)) {
            time += C /cur;
            cur += F;
        }
        time += X/cur;
        cout << "Case #" << k << ": ";
        cout << fixed;
        cout << setprecision(7) << time << endl;
    }
    return 0;
}

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

bool check(string x, string y) {
    string t1 = x+y;
    string t2 = y+x;
    for(int i=0;t1.length();i++) {
        if(t1[i]<t2[i]) return 0;
        if(t1[i]>t2[i]) return 1;
    }
    return 0;
}

int main() {
    int N;
    int M;
    string str[10];

    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> M;
        for(int j=0;j<M;j++)
            cin >> str[j];
        for(int j=0;j<M;j++) {
            for(int k=j+1;k<M;k++) {
                if(check(str[j],str[k])) {
                    swap(str[j],str[k]);
                }
            }
        }
        cout << "Case #" << i << ": ";
        for(int j=0;j<M;j++) {
            cout << str[j];
        }
        cout << endl;
    }

    return 0;
}

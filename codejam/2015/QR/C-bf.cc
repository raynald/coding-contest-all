#include<iostream>
#include<string>

using namespace std;

int main() {
    int T;
    string str;
    string x;
    int ans;
    int L, X;
    int i,j;
    int left, right;
    bool flag;
    int mat[5][5] = {{0,0,0,0,0}, {0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> L >> X;
        cin >> str;
        x = "";
        for(int i=0;i<X;i++) {
            x += str;
        }
        L *= X;
        ans = 1;
        for(int i=0;i<L;i++) {
            if(ans>0) ans = mat[ans][x[i]-'g'];
            else ans = - mat[-ans][x[i]-'g'];
        }
        cout << "Case #" << testcase << ": ";
        if(ans!=-1) {
            cout << "NO" << endl;
        } else {
            left = 1;
            flag = 0;
            for(int i=0;i<L;i++) {
                if(left>0) left= mat[left][x[i]-'g'];
                else left = - mat[-left][x[i]-'g'];
                right = 1;
                if(left!=2) continue;
                for(int j=L-1;j>i;j--) {
                    if(right>0) right= mat[x[j]-'g'][right];
                    else right = - mat[x[j]-'g'][-right];
                    if(right!=4) continue;
                    flag = 1;
                    break;
                }
                if(flag) break;
            }
            if(flag) cout << "YES" << endl; else cout << "NO" << endl;
        }
    }
    return 0;
}


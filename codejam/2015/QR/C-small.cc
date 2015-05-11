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
            right = 1;
            i = 0;
            j = L-1;
            for(;i<L;i++) {
                if(left>0) left = mat[left][x[i]-'g'];
                else {
                    left = -mat[-left][x[i]-'g'];
                }
                if(left==2) break;
            }
            if(left!=2) cout << "NO" << endl;
            else {
                for(;j>=0;j--) {
                    if(right>0) right = mat[right][x[j]-'g'];
                    else {
                        right = -mat[-right][x[j]-'g'];
                    }
                    if(right==4) break;
                }
                if(right==4 && i<j) cout << "YES" << endl; else cout << "NO" << endl;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int N, P, R, S;
int x, y, z;
int T;
bool flag;

string process(int R, int P, int S) {
    x = (P + R - S) / 2; 
    y = (P + S - R) / 2; 
    z = (R + S - P) / 2; 
    if (x < 0 || y < 0 || z < 0) {
        flag = 0;
        return "";
    }
    // cout << "round " << ": " << x << " " << y << " " << z << endl;
    if(x + y + z == 1)  {
        if (x == 1) return "PR";
        if (y == 1) return "PS";
        if (z == 1) return "RS";
    }
    else {
        string temp = process(z, x, y);
        if (flag == 0) return temp;
        string ans;
        for(int i = 0;i < temp.length();i ++) {
            if (temp[i] == 'P') ans += "PR";
            else if (temp[i] == 'R') ans += "RS";
            else if (temp[i] == 'S') ans += "PS";
        }
        return ans;
    }
}
 
string mergesort(string x) {
    if (x.length() > 2) {
        string a = mergesort(x.substr(0, x.length() / 2));
        string b = mergesort(x.substr(x.length() / 2));
        if (a > b) return b + a; else return a + b;
    } else return x;
}

int main() {
    string ans;

    cin >> T;
    for(int testcase = 1; testcase <= T; testcase ++) {
        cin >> N >> R >> P >> S;
        flag = 1;
        ans = process(R, P, S);
        cout << "Case #" << testcase << ": ";
        if (!flag) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << mergesort(ans) << endl;
        }
    }
    return 0;
}

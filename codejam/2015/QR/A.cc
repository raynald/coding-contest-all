#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main() {
    int T;
    int len;
    int num, ans;
    string str;

    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> len >> str;
        num = 0;
        ans = 0;
        for(int i=0;i<=len;i++) {
            if(i > num) {
                ans += i - num;
                num = i;
            }
            num += str[i] - '0';
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}

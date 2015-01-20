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

int T;
int ans;
int N, L;
long long str[151];
long long final[151];
map<long long, bool> mmap;
map<long long, bool> pam;
bool flag;
string s;
long long diff;
int sum;
map<long long, bool>::iterator got;


long long conv(string &s) {
    long long t=0;
    for(int j=0;j<L;j++) {
        t = t * 2;
        if(s[j]=='1') t++;
    }
    return t;
}

int main() {
    cin >> T;
    for(int k=1;k<=T;k++) {
        cin >> N >> L;
        mmap.clear();
        ans = L + 1;
        for(int i=0;i<N;i++)  {
            cin >> s;
            str[i] = conv(s);
        }
        for(int i=0;i<N;i++)  {
            cin >> s;
            final[i] = conv(s);
            mmap.insert(pair<long long, bool>(final[i],1));
        }
        for(int i=0;i<N;i++) {
            diff = str[0] ^ final[i];
            pam = mmap;
            pam.erase(final[i]);
            flag = 1;
            for(int j=1;j<N;j++) {
                got = pam.find(diff ^ str[j]);
                if(got==pam.end()) {
                    flag = 0;
                    break;
                }
                else {
                    pam.erase(got->first);
                }
            }
            if(flag) {
                sum = 0;
                while(diff>0) {
                    if(diff%2) sum++;
                    diff/=2;
                }
                if(sum<ans) ans = sum;
            }
        }
        cout << "Case #" << k << ": ";
        if(ans==L+1) cout << "NOT POSSIBLE"<<endl; else cout << ans << endl;
    }
    return 0;
}

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

vector<char> val;
vector<int> tmp;
vector<vector<int> > num;


bool check(string &s) {
    char old_char;
    int count;
    vector<int> tmp;

    old_char = s[0]; count = 1;
    tmp.clear();
    for(int j=1;j<s.length();j++) {
        if(s[j]==old_char) count++;
        else {
            if(old_char!= val[tmp.size()]) return 0;
            tmp.push_back(count);
            old_char = s[j];
            count = 1;
        }
    }
    if(old_char!=val[tmp.size()]) return 0;
    else tmp.push_back(count);
    if(num[0].size()!=tmp.size()) return 0;
    num.push_back(tmp);
    return 1; 
}

int abs(int x) {
    if(x<0) return -x; else return x;
}

int main() {
    int T;
    int N;
    bool flag;
    string str;
    char old_char;
    int count;
    int ans, sum, temp, temp2;
    cin >> T;
    for(int k=1;k<=T;k++) {
        cin >> N;
        cin >> str;
        old_char = str[0]; count = 1;
        flag = 1;
        val.clear();
        tmp.clear();
        num.clear();
        for(int j=1;j<str.length();j++) {
            if(str[j]==old_char) count++;
            else {
                val.push_back(old_char);
                tmp.push_back(count); 
                old_char = str[j];
                count = 1;
            }
        }
        val.push_back(old_char);
        tmp.push_back(count);
        num.push_back(tmp);
        cout << "Case #" << k << ": ";
        for(int i=1;i<N;i++) {
            cin >> str;
            if(!check(str)) flag = 0;
        }
        if(flag) {
            ans = 0;
            for(int i=0;i<num[0].size();i++) {
                tmp.clear();
                sum = 0; temp2=0;
                for(int l=0;l<N;l++) {
                    tmp.push_back(num[l][i]);
                }
                sort(tmp.begin(), tmp.end());
                temp = tmp[tmp.size()/2];
                for(int j=0;j<N;j++) {
                    temp2 += abs(tmp[j] - temp);
                }
                ans+=temp2;
            }
            cout << ans << endl;
        }
        else {
            puts("Fegla Won");
        }
    }

    return 0;
}


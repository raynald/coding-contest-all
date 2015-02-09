#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    vector<string> v;
    string s;
    int pos;

    while(cin >> s) {
        v.push_back(s);
    }
    s = v[v.size()-1];
    for(int i=0;i<s.length();i++) {
        if(s[i] == 'A') {
            pos = i;
            break;
        }
    }
    for(int j= v.size()-2;j>=0;j--) {
        s = v[j];
        for(int i=0;i<s.length();i++) {
            if(s[i]=='v') {
                if(i==pos) {
                    cout << "s";
                }
                if(i<pos) {
                    cout << pos-i << "l" << "s";
                }
                if(i>pos) {
                    cout << i-pos << "r" << "s";
                }
                pos = i;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}


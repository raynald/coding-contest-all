#include<iostream>
#include<map>

using namespace std;

string str;
map<char, string> mmap;
map<char, string>::iterator got;

int main() {
    mmap.insert(pair<char, string>('a', "11"));
    mmap.insert(pair<char, string>('b', "12"));
    mmap.insert(pair<char, string>('c', "13"));
    mmap.insert(pair<char, string>('d', "14"));
    mmap.insert(pair<char, string>('e', "15"));
    mmap.insert(pair<char, string>('f', "21"));
    mmap.insert(pair<char, string>('g', "22"));
    mmap.insert(pair<char, string>('h', "23"));
    mmap.insert(pair<char, string>('i', "24"));
    mmap.insert(pair<char, string>('k', "25"));
    mmap.insert(pair<char, string>('l', "31"));
    mmap.insert(pair<char, string>('m', "32"));
    mmap.insert(pair<char, string>('n', "33"));
    mmap.insert(pair<char, string>('o', "34"));
    mmap.insert(pair<char, string>('p', "35"));
    mmap.insert(pair<char, string>('q', "41"));
    mmap.insert(pair<char, string>('r', "42"));
    mmap.insert(pair<char, string>('s', "43"));
    mmap.insert(pair<char, string>('t', "44"));
    mmap.insert(pair<char, string>('u', "45"));
    mmap.insert(pair<char, string>('v', "51"));
    mmap.insert(pair<char, string>('w', "52"));
    mmap.insert(pair<char, string>('x', "53"));
    mmap.insert(pair<char, string>('y', "54"));
    mmap.insert(pair<char, string>('z', "55"));
    mmap.insert(pair<char, string>(' ', "0"));
    getline(cin, str);
    for(int i=0;i<str.length();i++) {
        if(str[i]==' ') {cout << str[i];}
        else {
            got = mmap.find(str[i]);
            string ans = got->second;
            for(int i=0;i<ans.length();i++) {
                switch(ans[i]) {
                    case '1': ans[i] = '5';break;
                    case '2': ans[i] = '2';break;
                    case '3': ans[i] = '3';break;
                    case '4': ans[i] = '1';break;
                    case '5': ans[i] = '4';break;
                }
            }
            int j = 0;
            for(got = mmap.begin(); got!=mmap.end();got++) {
                if(got->second == ans) {
                    cout << got->first;
                }
            }
        }
    }
    cout << endl;
    return 0;
}

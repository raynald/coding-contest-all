///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include "locksLib1.hpp"

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int diff(int x, int y) {
    if(x>y) return x-y; else return y-x;
}

void timing() {
    int time;
    int count, count_j;
    string t;
    string ans="";

    while(ans.length() < 100) {
        if(ans.size()<15) {
            for(int i=0;i<26;i++) {
                t = ans + char('a'+i);
                time = login(t.c_str());
                if(time == -1) {
                    answer(t);
                    return;
                } else {
                    if(time >=30*t.length()) {
                        ans = t;
                        break;
                    }
                }
                t = ans + char('A'+i);
                time = login(t.c_str());
                if(time == -1) {
                    answer(t);
                    return;
                } else {
                    if(time >=30*t.length()) {
                        ans = t;
                        break;
                    }
                }
            }
        } else {
            int count = 0;
            for(int i=0;i<26;i++) {
                t = ans + char('a'+i);
                time = 0;
                for(int j=0;j<10;j++) {
                    time += login(t.c_str());
                    if(time<0) {
                        answer(t);
                        return;
                    }
                }
                if(diff(time, 310*t.length())<2) {
                    ans = t;
                    break;
                }
                t = ans + char('A'+i);
                time = 0;
                for(int j=0;j<10;j++) {
                    time += login(t.c_str());
                    if(time<0) {
                        answer(t);
                        return;
                    }
                }
                if(diff(time, 310*t.length())<2) {
                    ans = t;
                    break;
                }
            }
        }
    }
}

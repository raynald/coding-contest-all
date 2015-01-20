//////////////////////
// SUBMIT THIS FILE //
//////////////////////

#include "locksLib2.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstring>

std::vector<int> crack_combination_lock(int combination_size) {
// your code goes here
    int n = combination_size;
    std::vector<int> v;
    std::vector<int> ans;
    bool check[110][10];
    bool flag;
    std::vector<int> p;
    
    for(int i=0;i<n;i++) {
        ans.push_back(-1);
        v.push_back(-1);
    }
    memset(check,0,sizeof(check));
    for(int i=0;i<=9;i++) {
        int start = 0;
        while(start<n) {
            std::fill(v.begin(), v.end(), -1);
            v[start] = i;
            if(start<n-1) v[start+1] = i;
            if(start<n-2) v[start+2] = i;
            if(start<n-3) v[start+3] = i;
            bool flag = login(v);
            check[start][i] = flag;
            if(!flag) {
                start += 4;
            } else {
                start ++;
            }
        }
    }
    for(int j=n-1;j>=0;j--) {
        flag = 0;
        p.clear();
        for(int i=0;i<=9;i++) {
            if(check[j][i]) {
                if(ans[j+1] != i && ans[j+2] != i && ans[j+3]!=i) {
                    ans[j] = i;
                    flag = 1;
                    break;
                } else {
                    p.push_back(i);
                }
            }
        }
        if(!flag) {
            if(p.size()==1) ans[j] = p[0];
            else {
                std::fill(v.begin(), v.end(), -1);
                v[j] = p[0];
                if(login(v)) ans[j] = p[0]; 
                else {
                    if(p.size()==2) ans[j] = p[1];
                    else {
                        std::fill(v.begin(), v.end(), -1);
                        v[j] = p[1];
                        if(login(v)) ans[j] = p[1]; 
                        else ans[j] = p[2];
                    }
                }
            }
        }
    }
    return ans;
}

//////////////////////
// SUBMIT THIS FILE //
//////////////////////

#include "locksLib3.hpp"
#include <iostream>
#include <cstring>

using namespace std;

std::vector<int> crack_password() {
	// your code goes here
    bool row[9][10];
    bool col[9][10];
    bool block[9][10];
    std::vector<int> ans;
    std::vector<int> test;

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));
    for(int i=0;i<81;i++) {
        ans.push_back(-1);
        test.push_back(-1);
    }
    for(int j=0;j<9;j++) {
        for(int k=0;k<9;k++) {
            for(int i=1;i<=9;i++) {
                if(ans[j*9+k]!=-1) break;
                if(row[j][i]) continue;
                if(col[k][i]) continue;
                if(block[j/3*3+k/3][i]) continue;
                std::fill(test.begin(), test.end(), -1);
                test[j*9+k] = i;
                if(is_loose(test)) {
                    row[j][i] = 1;
                    col[k][i] = 1;
                    block[j/3*3+k/3][i] = 1;
                    ans[j*9+k]=i;
                }
            }
        }
    }
    return ans;
}

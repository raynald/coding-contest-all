//////////////////////
// SUBMIT THIS FILE //
//////////////////////

#include "spyLib2.hpp"
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

vector<unsigned char> hint;
vector<unsigned char> rec;
int cnt = 0;
int rec_cnt = 0;

void scan_marmot(unsigned long long int id){		// runs in Heidi's thread
	// your code goes here
    cnt ++;
    if(cnt==1) {
        for(int i=0;i<2*get_N();i++) {
            hint.push_back(0);
        }
    }
    hint[id/8] |= 1 << (id%8);
    if(cnt==get_N()) {
        for(int i=0;i<2*cnt;i ++) {
            send_hint(hint[i]);
        }
    }
}

void receive_hint(unsigned char info){				// runs in the marmots' thread
    rec.push_back(info);
}

unsigned char is_spy(unsigned long long int id){	// runs in the marmots' thread
    if(int(rec[id/8] & 1 << (id%8)) == 1 << (id%8)) return 0; else return 1;
}


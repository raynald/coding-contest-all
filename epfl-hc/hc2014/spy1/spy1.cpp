//////////////////////
// SUBMIT THIS FILE //
//////////////////////

#include "spyLib1.hpp"
#include<string>
#include<map>

using namespace std;

map<int , bool> mmap;
map<int , bool>::iterator got;
int count=0;
int in;

void scan_marmot(unsigned long long int id){		// runs in Heidi's thread
	// your code goes here
	/* make your calls to send_hint() */
    send_hint(id/256);
    send_hint(id%256);
}

void receive_hint(unsigned char info){				// runs in the marmots' thread
    count ++;
    if(count%2==0) {
        in = in*256+info;
        mmap.insert(pair<int ,bool>(in, 1));
    }
    else in = info;
}

unsigned char is_spy(unsigned long long int id){	// runs in the marmots' thread
    got = mmap.find(id);
    if(got==mmap.end()) return 1; else return 0;
}

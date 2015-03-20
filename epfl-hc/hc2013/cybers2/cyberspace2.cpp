///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include "cyberspaceLib2.hpp"

int place_exit(int N, int M){
    int q = N/2;
    int count =0;
    while(q!=0) {
        if(q%2) count++;
        q/=2;
    }
    q = N/2;
    int t = q;
    int s = 1;
    if(count<M) {
        for(int i=0;i<M-count;i++) {
            while(t%2) {
                t/=2;
                s*=2;
            }
            q += s;
            t/=2;
            s*=2;
        }
    } else {
        for(int i=0;i<count-M;i++) {
            q = q - (q & (-q));
        }
    }
    return q;
}

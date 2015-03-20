///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include "cyberfoodLib1.hpp"

int count_flavours(long long int first){
    long long int p, q;
    p = q = first;
    do {
        q = eat(eat(q));
        p = eat(p);
    } while(q!=p);
    int step = 1;
    q = eat(q);
    while(q!=p) {
        step ++;
        q = eat(q);
    }
    q = first;
    while(p!=q) {
        p = eat(p);
        q = eat(q);
        step ++;
    }
	return step;
}

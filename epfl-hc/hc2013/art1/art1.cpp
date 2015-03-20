///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////
#include <vector>
#include "artLib1.hpp"
using namespace std;

vector<int> draw_charming_painting(int N) {
    vector<int> p;
    int a = 2 * N - 1;
    int b = 1;
    while(a>b) {
        p.push_back(a);
        p.push_back(b);
        a-=2;
        b+=2;
    }
    if(a==b) p.push_back(a);
    return p;
}

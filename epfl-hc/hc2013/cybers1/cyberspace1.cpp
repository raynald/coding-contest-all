///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include "cyberspaceLib1.hpp"
using namespace std;

int entry_time(int a[], int p[], int N){
    int ans = 0;
    for(int i=0;i<=N;i++) {
        if(ans<a[i]) {
            ans = a[i];
        }
        ans += p[i];
    }
	return ans;
}


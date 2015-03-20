///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////
#include"portalLib1.hpp"
#include<cmath>

// see portalLib1.h for the cube struct: It has int x and int y
void speed_assessment(cube c, int N, double s[]){
    int T = 0;
    int L = 0;
    for(int i=0;i<N;i++) {
        double t = c.x / s[i];
        if(t*t/2>=c.y && t*t/2<=c.y+1) L++;
        else {
            t = sqrt(c.y * 2);
            if(t*s[i]>=c.x && t*s[i]<=c.x+1) T++;
        }
    }
	answer(T,L);
}

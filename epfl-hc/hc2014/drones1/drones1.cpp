///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include "dronesLib1.hpp"

#include<queue>
#include<cmath>
#include<iostream>

using namespace std;

double norm(const Vec2d &vec) {
    return sqrt( vec.x * vec.x + vec.y * vec.y);
}

double scala(Vec2d v1, Vec2d v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double vect(Vec2d v1, Vec2d v2) {
    return v1.x * v2.y - v1.y * v2.x;
}


double minRange(int nRouter, int nTraj){
    vector<Vec2d> route;
    vector<Vec2d> traj;
    Vec2d vec, rv, rv2;
    double sum, ans, tmp;
    bool tt;

    sum = -1;
    route.clear();
    traj.clear();
    for (int i = 0;i < nRouter; i++) {
        readRouter(vec);
        route.push_back(vec); 
    }
    for (int i = 0;i < nTraj; i++) {
        readTrajPoint(vec); 
        traj.push_back(vec); 
    }
    for (int i = 0;i < nRouter; i++) {
        ans = int(2e9);
        for (int j = 0;j < nTraj - 1; j++) {
            vec.x = traj[j+1].x - traj[j].x; 
            vec.y = traj[j+1].y - traj[j].y; 
            rv.x = route[i].x - traj[j].x;
            rv.y = route[i].y - traj[j].y;
            rv2.x = route[i].x - traj[j+1].x;
            rv2.y = route[i].y - traj[j+1].y;

            tmp = scala(vec, rv) / norm(vec);
            if (tmp < 0 || tmp > norm(vec)) {
                tmp = min(norm(rv), norm(rv2));
            } else {
                tmp = vect(vec, rv) / norm(vec);
                if(tmp<0) tmp = -tmp;
            }
            ans = min(ans, tmp);
        }
        sum = max(ans, sum);
    }
	return sum;
}


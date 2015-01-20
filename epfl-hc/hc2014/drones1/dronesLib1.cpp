/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include "dronesLib1.hpp"
using namespace std;

queue<Vec2d> routers;
queue<Vec2d> traj;
Vec2d trashV;
double trashD;

bool uniRead(Vec2d &p, double &x, double &y, queue<Vec2d> &q){
	if (q.empty()) return false;
	p = q.front(); q.pop();
	x = p.x; y = p.y;
	return true;
}

bool readRouter(Vec2d &p){
	return uniRead(p, trashD, trashD, routers);
}
bool readRouter(double &x, double &y){
	return uniRead(trashV, x, y, routers);
}

bool readTrajPoint(Vec2d &p){
	return uniRead(p, trashD, trashD, traj);
}
bool readTrajPoint(double &x, double &y){
	return uniRead(trashV, x, y, traj);
}

int main(){
	int nr,nt;
	double x,y,sol;
	cin >> nr >> nt;
	while (nr--){
		cin >> x >> y;
		routers.push(Vec2d(x,y));
	}
	while (nt--){
		cin >> x >> y;
		traj.push(Vec2d(x,y));
	}
	cin >> sol;
	if (fabs(sol-minRange(routers.size(),traj.size()))<=0.001)
		cout << "Correct" << endl;
	else
		cout << "Wrong" << endl;
	return 0;
}

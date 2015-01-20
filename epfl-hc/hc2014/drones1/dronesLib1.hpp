/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

// for your convenience
typedef struct Vec2d{
	double x;
	double y;
	Vec2d(){}
	Vec2d(double xx, double yy) : x(xx), y(yy) {}
} Vec2d;

// function you have to code
double minRange(int nRouter, int nTraj);

// function to call to read in router coordinates one by one
// returns false once all routers are read in
bool readRouter(double &x, double &y);
bool readRouter(Vec2d &p);

// function to call to read in trajectory coordinates one by one
// returns false once all routers are read in
bool readTrajPoint(double &x, double &y);
bool readTrajPoint(Vec2d &p);

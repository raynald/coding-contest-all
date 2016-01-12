/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <stdbool.h>

// point in 2D space
typedef struct Vec2d{
	double x;
	double y;
} Vec2d;

// Function you have to code: Problem initialization. 
// May be called multiple times. Specifies number of outer and inner polygons
void init(int nOuter, int nInner);

// function you have to code
double minRisk(const Vec2d router);

// functions to call to read in outer/inner Polygon coordinates one by one
// idx = 0..nOuter-1 or 0..nInner-1 is the index of the polygon to read
// you may choose to call either flavor, but each coordinate can only be
// read in once
// coordinates of the polygons come in counterclockwise order
// returns false once all coordinates of a Polygon are read in

bool readOuter(int idx, double *x, double *y);
bool readOuterVec2d(int idx, Vec2d *p);

bool readInner(int idx, double *x, double *y);
bool readInnerVec2d(int idx, Vec2d *p);

// functions for your convenience: plot point/line with different colors
// first color is 1
void plotLine(const Vec2d a, const Vec2d b, int color);
void plotPoint(const Vec2d a, int color);


///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////
#include "dryrunLib3.hpp"

void lineThrough(Point2D *a, Point2D *b) {
	//set a and b to be two points separating the polygons
	a->x = 30;
	a->y = 90;
	b->x = 70; 
	b->y = 50;
    plotLine(*a,*b, 2);
  	// don't forget to visualize ;)
}


///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include <stdlib.h>
#include "artLib2.h"

// If you receive COULD BE CORRECT after compile, it doesn't mean that the solution works
// correctly on the tests, it's because there is no checker supplied with this problem

int* draw_literate_painting(int N, int M, int* a, int* b) {
	// colors should contain dots' colors
	int* colors = (int*) calloc(N, sizeof(int));
	// tour should contain the tour composed of little paths
	// we allocate 3*N memory, so any valid tour would fit
	// if your tour is less than 3*N, then fill the remaining values with 0
	int* tour = (int*) calloc(3*N, sizeof(int));
	// Insert your code here
	
	
	// Don't modify this code
	int* ret = answer(colors, tour, N);
	free(colors);
	free(tour);
	return ret;
}
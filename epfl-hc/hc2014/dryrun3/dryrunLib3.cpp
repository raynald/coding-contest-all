/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include "dryrunLib3.hpp"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
	Point2D a, b;
} Segment;

static FILE *gnuplot;
static const int MIC = 0;
static const int MAC = 100;

static double cross(Point2D v1, Point2D v2){
	return v1.x*v2.y - v1.y*v2.x;
}

void plotLine(Point2D a, Point2D b, int color){
    fprintf(gnuplot, "plot '-' w l lt %d\n%f %f\n%f %f\ne\n", color, a.x, a.y, b.x, b.y);
}

void plotPoint(Point2D a, int color){
    fprintf(gnuplot, "plot '-' w p lt %d\n%f %f\ne\n", color, a.x, a.y);
}

int main(){
    // init gnuplot
    gnuplot = popen("gnuplot --persist","w");
	fputs("set terminal x11 size 900,900\n",gnuplot);
	fputs("set multiplot\n",gnuplot);
	fputs("unset key\n",gnuplot);
	fprintf(gnuplot,"set xrange [%d:%d]\n",MIC,MAC);
	fprintf(gnuplot,"set yrange [%d:%d]\n",MIC,MAC);
	fputs("set size ratio -1\n",gnuplot);

  	// fetch the two polygons from stdin
  	Point2D p1[1000], p2[1000];
  	int i, n1=-1, n2=-1;
  	fprintf(gnuplot, "plot '-' w l lt 1\n");
  	do{
  		n1++;
  		scanf("%lf %lf", &(p1[n1].x), &(p1[n1].y) );
  		if( p1[n1].x != -1)
  			fprintf(gnuplot, "%lf %lf\n", p1[n1].x, p1[n1].y );
  	} while (p1[n1].x != -1);
  	p1[n1].x = p1[0].x; p1[n1].y = p1[0].y;
  	fprintf(gnuplot, "%f %f\n", p1[n1].x, p1[n1].y );
  	do{
  		n2++;
  		scanf("%lf %lf", &(p2[n2].x), &(p2[n2].y) );
  		if( p2[n2].x != -1)
  			fprintf(gnuplot, "%lf %lf\n", p2[n2].x, p2[n2].y );
  	} while (p2[n2].x != -1);
  	p2[n2].x = p2[0].x; p2[n2].y = p2[0].y;
  	fprintf(gnuplot, "%f %f\n", p2[n2].x, p2[n2].y );
	fprintf(gnuplot, "e\n");
	
	// fetch the vector from user
	Point2D a = {0,0}, b = {0,0};
	lineThrough(&a,&b);
	Point2D v1 = { b.x-a.x, b.y-a.y };
		
	// verify separating
	Point2D v2 = { p1[0].x-a.x, p1[0].y-a.y };
	for (i=0; i<n1; i++){
		Point2D v3 = { p1[i].x-a.x, p1[i].y-a.y };
		if ( cross( v1, v2 ) * cross( v1, v3 ) < 0 ){
			printf("Wrong\n");
			exit(0);
		}
	}
	Point2D v4 = { p2[0].x-a.x, p2[0].y-a.y };
	for (i=0; i<n2; i++){
		Point2D v3 = { p2[i].x-a.x, p2[i].y-a.y };
		if ( cross( v1, v4 ) * cross( v1, v3 ) < 0 ){
			printf("Wrong\n");
			exit(0);
		}
	}
	if ( cross( v1, v2 ) * cross( v1, v4 ) > 0 ){
		printf("Wrong\n");
			exit(0);
	}
	printf("Correct\n");
	return 0;
}

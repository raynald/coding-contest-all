/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dronesLib2.h"

// Minimal and maximal coordinate
#define MIC 0
#define MAC 100
// Maximal edge quantity
#define MXE

typedef struct {
	Vec2d *data;
	int size;
	int it;
} PtQueue;

PtQueue *inner, *outer;

/**
 * DATA INTERFACE
 */

bool uniRead(Vec2d *p, double *x, double *y, PtQueue *src){
	if (src->it == src->size) return false;
	if (p)
		*p = src->data[src->it];
	if (x && y){
		*x = src->data[src->it].x;
		*y = src->data[src->it].y;
	}
	++src->it;
	return true;
}

bool readInnerVec2d(int idx, Vec2d *p){
	return uniRead(p, NULL, NULL, inner + idx);
}
bool readInner(int idx, double *x, double *y){
	return uniRead(NULL, x, y, inner + idx);
}

bool readOuterVec2d(int idx, Vec2d *p){
	return uniRead(p, NULL, NULL, outer + idx);
}
bool readOuter(int idx, double *x, double *y){
	return uniRead(NULL, x, y, outer + idx);
}

/**
 * VISUALIZATION
 */
 
static FILE *gnuplot;

void plotLine(const Vec2d a, const Vec2d b, int color){
  fprintf(gnuplot, "plot '-' w l lt %d\n%lf %lf\n%lf %lf\ne\n",
    color, a.x, a.y, b.x, b.y);
}

void plotPoint(const Vec2d a, int color){
  fprintf(gnuplot, "plot '-' w p lt %d\n%lf %lf\ne\n",
    color, a.x, a.y);
}


int main(){
  int ntc,no,ni,nq,tc,i,buffersz;
  Vec2d *buffer;
	double x,y,r, *contestantAnswers;
	
	// for each testcase
	scanf("%d",&ntc);
	for (tc=0; tc<ntc; ++tc){
	  // init gnuplot
	  gnuplot = popen("gnuplot --persist","w");
	  fputs("set terminal wxt size 900,900\n",gnuplot);
	  fputs("set multiplot\n",gnuplot);
	  fputs("unset key\n",gnuplot);
	  fprintf(gnuplot,"set xrange [%d:%d]\n",MIC,MAC);
	  fprintf(gnuplot,"set yrange [%d:%d]\n",MIC,MAC);
	
	  // read params
	  scanf("%d %d %d",&no, &ni, &nq);
	  inner = (PtQueue *) malloc(ni*sizeof(PtQueue));
	  outer = (PtQueue *) malloc(no*sizeof(PtQueue));
	  
	  // read polygons
	  fprintf(gnuplot,"plot '-' w l lt 1\n");
	  for (i=0; i<no; ++i){
	    buffer = (Vec2d*) malloc(1000*sizeof(Vec2d));
	    for (buffersz = 0; true; ++buffersz){
		    scanf("%lf %lf",&buffer[buffersz].x, &buffer[buffersz].y);
		    if (buffer[buffersz].x<0) break;
		    fprintf(gnuplot,"%lf %lf\n",buffer[buffersz].x,buffer[buffersz].y);
	    }
	    outer[i].data = (Vec2d*) realloc(buffer, buffersz*sizeof(Vec2d));
	    outer[i].size = buffersz;
	    outer[i].it = 0;
	    fprintf(gnuplot,"%lf %lf\n\n",outer[i].data[0].x, outer[i].data[0].y);
	  }
	  fprintf(gnuplot, "e\n");
	  fprintf(gnuplot,"plot '-' w l lt 1\n");
	  for (i=0; i<ni; ++i){
	    buffer = (Vec2d*) malloc(1000*sizeof(Vec2d));
	    for (buffersz = 0; true; ++buffersz){
		    scanf("%lf %lf",&buffer[buffersz].x, &buffer[buffersz].y);
		    if (buffer[buffersz].x<0) break;
		    fprintf(gnuplot,"%lf %lf\n",buffer[buffersz].x,buffer[buffersz].y);
	    }
	    inner[i].data = (Vec2d*) realloc(buffer, buffersz*sizeof(Vec2d));
	    inner[i].size = buffersz;
	    inner[i].it = 0;
	    fprintf(gnuplot,"%lf %lf\n\n",inner[i].data[0].x, inner[i].data[0].y);
	  }
	  fprintf(gnuplot, "e\n");
	  
	  // call contestant init
	  init(no,ni);
	
	  // query contestant
	  contestantAnswers = (double*)malloc(nq*sizeof(double));
	  fprintf(gnuplot,"plot '-' w p\n");
	  for (i=0; i<nq; ++i){
		  scanf("%lf %lf",&x, &y);
		  fprintf(gnuplot,"%lf %lf\n",x,y);
		  contestantAnswers[i] = minRisk((Vec2d){.x = x, .y = y});
	  }
	  fprintf(gnuplot, "e\n");
	  
	  // check contestant answers
	  for (i=0; i<nq; ++i){
	    scanf("%lf",&x);
	    if (fabs(contestantAnswers[i]-x)>0.001){
	      printf("Wrong: Fails at query %d of test %d with %lf instead of %lf\n",
	          i,tc,contestantAnswers[i],x);
	      return 0;
	    }
	  }
	  
	  // clean up memory
	  free(contestantAnswers);
	  for (i=0; i<ni; ++i) free(inner[i].data);
	  free(inner);
	  for (i=0; i<no; ++i) free(outer[i].data);
	  free(outer);
	}
	printf("Correct\n");
	return 0;
}

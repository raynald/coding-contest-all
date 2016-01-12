/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include "dronesLib2.hpp"
using namespace std;

// Minimal and maximal coordinate
#define MIC 0
#define MAC 100

vector<queue<Vec2d> > outer;
vector<queue<Vec2d> > inner;
Vec2d trashV;
double trashD;

/**
 * DATA INTERFACE
 */

bool uniRead(Vec2d &p, double &x, double &y, queue<Vec2d> &q){
	if (q.empty()) return false;
	p = q.front(); q.pop();
	x = p.x; y = p.y;
	return true;
}

bool readOuter(int idx, Vec2d &p){
	return uniRead(p, trashD, trashD, outer[idx]);
}
bool readOuter(int idx, double &x, double &y){
	return uniRead(trashV, x, y, outer[idx]);
}

bool readInner(int idx, Vec2d &p){
	return uniRead(p, trashD, trashD, inner[idx]);
}
bool readInner(int idx, double &x, double &y){
	return uniRead(trashV, x, y, inner[idx]);
}

/**
 * VISUALIZATION
 */
 
static FILE *gnuplot;

void plotLine(const Vec2d &a, const Vec2d &b, int color){
  fprintf(gnuplot, "plot '-' w l lt %d\n%lf %lf\n%lf %lf\ne\n",
    color, a.x, a.y, b.x, b.y);
}

void plotPoint(const Vec2d &a, int color){
  fprintf(gnuplot, "plot '-' w p lt %d\n%lf %lf\ne\n",
    color, a.x, a.y);
}


int main(){
	int ntc,no,ni,nq;
	double x,y;
	
	// for each testcase
	cin >> ntc;
	for (int tc=0; tc<ntc; ++tc){
	  // init gnuplot
	  gnuplot = popen("gnuplot --persist","w");
	  fputs("set terminal x11 size 900,900\n",gnuplot);
	  fputs("set multiplot\n",gnuplot);
	  fputs("unset key\n",gnuplot);
	  fprintf(gnuplot,"set xrange [%d:%d]\n",MIC,MAC);
	  fprintf(gnuplot,"set yrange [%d:%d]\n",MIC,MAC);
	
	  // read params
	  cin >> no >> ni >> nq;
	  outer.resize(no);
	  inner.resize(ni);
	
	  // read polygons
	  fprintf(gnuplot,"plot '-' w l lt 1\n");
	  for (int i=0; i<no; ++i){
	    while (true){
		    cin >> x >> y;
		    if (x<0) break;
		    outer[i].push(Vec2d(x,y));
		    fprintf(gnuplot,"%lf %lf\n",x,y);
	    }
	    fprintf(gnuplot,"%lf %lf\n\n",outer[i].front().x, outer[i].front().y);
	  }
	  fprintf(gnuplot, "e\n");
	  fprintf(gnuplot,"plot '-' w l lt 1\n");
	  for (int i=0; i<ni; ++i){
	    while (true){
		    cin >> x >> y;
		    if (x<0) break;
		    inner[i].push(Vec2d(x,y));
		    fprintf(gnuplot,"%lf %lf\n",x,y);
	    }
	    fprintf(gnuplot,"%lf %lf\n\n",inner[i].front().x, inner[i].front().y);
	  }
	  fprintf(gnuplot, "e\n");
	
	  // call contestant init
	  init(no,ni);
	
	  // query contestant
	  vector<double> contestantAnswers;
	  fprintf(gnuplot,"plot '-' w p\n");
	  while (nq--){
		  cin >> x >> y;
		  fprintf(gnuplot,"%lf %lf\n",x,y);
		  contestantAnswers.push_back(minRisk(Vec2d(x,y)));
	  }
	  fprintf(gnuplot, "e\n");
	  
	  // check contestant answers
	  for (int i=0; i<contestantAnswers.size(); ++i){
	    cin >> x;
	    if (fabs(contestantAnswers[i]-x)>0.001){
	      printf("Wrong: Fails at query %d of test %d with %lf instead of %lf\n",
	          i,tc,contestantAnswers[i],x);
	      return 0;
	    }
	  }
	}
	printf("Correct\n");
	return 0;
}

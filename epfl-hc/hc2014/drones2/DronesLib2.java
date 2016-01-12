/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////
import java.util.*;
import java.io.*;
import java.awt.geom.Point2D;

public class DronesLib2 {
  /**
   * FUNCTIONS YOU MAY CALL
   *
   * write requested data to passed references, returns false once all
   * the points of a polygon are read
   */
  public static Point2D readOuter(int idx){
	  return uniRead(outer.get(idx));
  }
  
  public static Point2D readInner(int idx){
	  return uniRead(inner.get(idx));
  }
  
  /**
   * Functions you may call to visually debug your solution
   */
  public static void plotLine(Point2D a, Point2D b, int color){
    gpStream.printf("plot '-' w l lt %d\n%f %f\n%f %f\ne\n",
      color, a.getX(), a.getY(), b.getX(), b.getY());
  }

  public static void plotPoint(Point2D a, int color){
    gpStream.printf("plot '-' w p lt %d\n%f %f\ne\n",
      color, a.getX(), a.getY());
  }

  
  private static final int MIC = 0;
  private static final int MAC = 100;
  
  private static Vector<Queue<Point2D> > outer, inner;
  private static Point2D trashV = new Point2D.Double();
  private static double trashD;
  
  private static Point2D uniRead(Queue<Point2D> q){
    if (q.isEmpty()) return null;
    return q.poll();
  }
  
  /**
   * VISUALIZATION
   */
   
  private static Process gnuplot;
  private static PrintStream gpStream;

  public static void main(String args[]){
    int ntc,no,ni,nq;
	  double x,y,r;
	  Scanner sc = new Scanner(System.in);
	
	  // for each testcase
	  ntc = sc.nextInt();
	  for (int tc=0; tc<ntc; ++tc){
	    // init gnuplot
	    try{
  	    gnuplot = Runtime.getRuntime().exec("gnuplot --persist");
  	  }
  	  catch (IOException e){
  	    System.out.println(e.getMessage());
  	  }
	    gpStream = new PrintStream(gnuplot.getOutputStream(),true);
	    gpStream.printf("set terminal wxt size 900,900\n");
	    gpStream.printf("set multiplot\n");
	    gpStream.printf("unset key\n");
	    gpStream.printf("set xrange [%d:%d]\n",MIC,MAC);
	    gpStream.printf("set yrange [%d:%d]\n",MIC,MAC);
	
	    // read params
	    no = sc.nextInt();
	    ni = sc.nextInt();
	    nq = sc.nextInt();
	    outer = new Vector<Queue<Point2D> >(no);
	    inner = new Vector<Queue<Point2D> >(ni);
	
	    // read polygons
	    gpStream.printf("plot '-' w l lt 1\n");
	    for (int i=0; i<no; ++i){
	      outer.add(new LinkedList<Point2D>());
	      while (true){
		      x = sc.nextDouble(); y = sc.nextDouble();
		      if (x<0) break;
		      outer.get(i).add(new Point2D.Double(x,y));
		      gpStream.printf("%f %f\n",x,y);
	      }
	      gpStream.printf("%f %f\n\n",outer.get(i).peek().getX(), 
	          outer.get(i).peek().getY());
	    }
	    gpStream.printf( "e\n");
	    gpStream.printf("plot '-' w l lt 1\n");
	    for (int i=0; i<ni; ++i){
	      inner.add(new LinkedList<Point2D>());
	      while (true){
		      x = sc.nextDouble(); y = sc.nextDouble();
		      if (x<0) break;
		      inner.get(i).add(new Point2D.Double(x,y));
		      gpStream.printf("%f %f\n",x,y);
	      }
	      gpStream.printf("%f %f\n\n",inner.get(i).peek().getX(), 
	          inner.get(i).peek().getY());
	    }
	    gpStream.printf( "e\n");
	    
	    // call contestant init
	    Drones2.init(no,ni);
	
	    // query contestant
	    Vector<Double> contestantAnswers = new Vector<Double>();
	    gpStream.printf("plot '-' w p\n");
	    while (nq-- != 0){
		    x = sc.nextDouble(); y = sc.nextDouble();
		    gpStream.printf("%f %f\n",x,y);
		    contestantAnswers.add(Drones2.minRisk(new Point2D.Double(x,y)));
	    }
	    gpStream.printf( "e\n");
	    
	    // check contestant answers
	    for (int i=0; i<contestantAnswers.size(); ++i){
	      x = sc.nextDouble();
	      if (Math.abs(contestantAnswers.get(i)-x)>0.001){
	        System.out.printf("Wrong: Fails at query %d of test %d with %f " +
	            "instead of %f\n",i,tc,contestantAnswers.get(i),x);
	        return;
	      }
	    }
	  }
	  System.out.printf("Correct\n");
  }
}

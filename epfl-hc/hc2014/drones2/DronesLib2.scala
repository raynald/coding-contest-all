/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

object DronesLib2 {
  
  /** This class manages a gnuplot process, and can be used to visually analyze
   *  your solution */
  class Gnuplot {
    def plotLine(a: Vec2d, b: Vec2d, color: Int = 1) {
      printf("plot '-' w l lt %d\n%f %f\n%f %f\ne\n",
          color, a.x, a.y, b.x, b.y)
    }
    
    def plotPolygon(polygon: Seq[Vec2d], color: Int = 1) {
      printf("plot '-' w l lt %d\n", color)
      polygon.foreach { p => printf("%f %f\n", p.x, p.y) }
      printf("%f %f\ne\n", polygon(0).x, polygon(0).y)
    }
    
    def plotPoint(p: Vec2d, color: Int = 1) {
      printf("plot '-' w p lt %d\n%f %f\ne\n",
          color, p.x, p.y)
    }

    def plotProblem(outer: Seq[Seq[Vec2d]], inner: Seq[Seq[Vec2d]]) {
      outer.foreach { polygon => plotPolygon(polygon, 1) }
      inner.foreach { polygon => plotPolygon(polygon, 2) }
    }
    
    private def printf(formatString : String, items : Any*) { 
      stream.printf(formatString.format(items : _*))
      stream.flush()
    }
      
    // Initialize gnuplot
    val gnuplot = Runtime.getRuntime().exec("gnuplot --persist")
    val stream = new java.io.PrintStream(gnuplot.getOutputStream(), true)
    printf("set multiplot\n");
    printf("unset key\n");
    printf("set xrange [-0.5:100.5]\n");
    printf("set yrange [-0.5:100.5]\n");
  }
  
  private def readPolygon(s: java.util.Scanner): Seq[Vec2d] = {
    val polygon = collection.mutable.ArrayBuffer.empty[Vec2d]
    var x = s.nextDouble()
    var y = s.nextDouble()
    while (x >= 0 && y >= 0) {
      polygon += Vec2d(x, y)
      x = s.nextDouble()
      y = s.nextDouble()
    }
    polygon
  }
  
  private def readQuery(s: java.util.Scanner): Vec2d = {
    val x = s.nextDouble()
    val y = s.nextDouble()
    Vec2d(x, y)
  }
  
  def main(args: Array[String]): Unit = {
    // start
    val s = new java.util.Scanner(System.in)
    val ntc = s.nextInt()
    
    // test cases
    for (tc <- 1 to ntc) {
      val no = s.nextInt()
      val ni = s.nextInt()
      val nq = s.nextInt()

      val outer = (0 until no) map { i => readPolygon(s) }
      val inner = (0 until ni) map { i => readPolygon(s) }
      val queries = (0 until nq) map { i => readQuery(s) }
      val solutions = (0 until nq) map {i => s.nextDouble() }
      
      // Construct a testcase objects, and run the queries
      val testCase = Drones2(outer, inner)

      (0 until nq).foreach { i =>
        val answer = testCase.minRisk(queries(i))
        if ((answer - solutions(i)).abs > 0.001) {
          println("Incorrect: fails at query %d of test %d with %f instead of %f".format(
              i + 1, tc, answer, solutions(i)))
          sys.exit(0)
        }
      }
    }

    println("Correct") 
  }
}

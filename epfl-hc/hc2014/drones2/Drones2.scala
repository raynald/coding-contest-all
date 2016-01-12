///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

/** A point in 2D space. You may modify this, as long as you don't change the
 *  constructor signature */
case class Vec2d(val x: Double, val y: Double)

/** The class you have to code.
 *  
 *  This class will be instanciated several times. Its constructor receives two
 *  sequences of polygons, the outer and inner polygons. Each polygon is
 *  represented as a sequence of points, in counterclockwise order.
 *
 *  Once an object of this class has been created, the minRisk method will be
 *  called several times. It receives the coordinates of a router, and the
 *  minimum range of the wireless device. It must return the smallest possible
 *  distance over risky territory that needs to be covered by the drone.
 */
case class Drones2(val outer: Seq[Seq[Vec2d]], val inner: Seq[Seq[Vec2d]]) {

  def minRisk(router: Vec2d): Double = 0
}

package shapes;
import java.text.DecimalFormat;
public class Circle implements Shape {
	private double radius;
	/** * @return */
	private ShapeArea obj = () -> Math.PI * getRadius() * getRadius();
	
	/**
	 * @param radius
	 * @throws CircleException
	 */
	public Circle(double radius) throws CircleException {
		if (radius > 0) {
			this.radius = radius;			
		} else {
			throw new CircleException("Invalid radius!");
		}
	}
	public void setRadius(double radius) throws CircleException {
		if (radius > 0) {
			this.radius = radius;
		} else {
			throw new CircleException("Invalid radius!");
		}
	}
	public double getRadius() {
		return radius;
	}
	/**
	  * @return 
	 */
	@Override
	public double calculatePerimeter() {
		return 2 * radius * Math.PI;
	}
	
	/**
	 * @return 
	 */
	@Override
	public String toString() {
		return getClass().getSimpleName() + " {r=" + getRadius() + "} perimeter = "
				+ new DecimalFormat("0.00000").format(calculatePerimeter()) 
				+ " area= " + new DecimalFormat("0.00000").format(obj.calculateArea());
	}
}
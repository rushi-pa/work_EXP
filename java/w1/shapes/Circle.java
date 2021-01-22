package shapes;


public class Circle implements Shape {
    private double radius;

    Circle(double radius) throws Exception {
            if(radius > 0.0) {
                this.radius = radius;
            } else{
                throw new Exception("Invalid radius!");
            }
    }

    @Override
    public double getPerimeter(){
        return (2*Math.PI*radius);
    }
    public String getDimensions() {
        return ("r=" + String.format("%.1f", radius));
    }
}

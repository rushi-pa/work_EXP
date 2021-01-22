package shapes;
public class Parallelogram implements Shape {
    double width;
    double height;
    Parallelogram(double width, double height) throws Exception {
        if (width > 0.0 || height > 0.0) {
            this.width = width;
            this.height = height;
        } else 
            throw new Exception("Invalid side(s)!");
    }
    @Override
    public double getPerimeter() {
        return ((2 * width) + (2 * height));
    }
    public String getDimensions() {
        return ("w=" + width + ", h=" + height);
    }
}

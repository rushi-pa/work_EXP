package shapes;
public class Rectangle extends Parallelogram {
    double width;
    double length;
    Rectangle(double width, double length) throws Exception{
        super(width, length);
        this.width = super.width;
        this.length = super.height;
    }
    @Override
    public double getPerimeter(){
        return (2*width + 2*length);
    }
    public String getDimensions(){
        return ("w=" + width + ", l=" + length);
    }
}
package shapes;
public class Square extends Rectangle {
    private double side;
    Square(double side) throws Exception{
        super(side, side);
        this.side = super.width;
    }
    @Override
    public double getPerimeter() {
        return (side*4);
    }
    public String getDimensions() {
        return ("s=" + side);
    }
}

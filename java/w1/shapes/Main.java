package shapes;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class Main {
    public static void main(String[] args) {
        System.out.println("------->JAC 444 Assignment 1<-------");
        System.out.println("------->Task 1 ... <-------");
        
// the first try and while loop to count the memory needed to allocate to the array.
        String file_N = "shapes/shapes.txt";
        int NoOfObj = 0;
        Shape[] shp_obj;
        String temp;
        try (BufferedReader buff_r = new BufferedReader(new FileReader(file_N))) {
            while ((temp = buff_r.readLine()) != null) {
                try {
                    String[] values = temp.split(",");
                    if (values[0].equals("Triangle") || values[0].equals("Circle") || values[0].equals("Square") || values[0].equals("Rectangle") ||  values[0].equals("Parallelogram") ) {
                        for (int i = 1; i < values.length; i++) {
                            if (Double.valueOf(values[i]) <= 0.0)
                                throw new Exception();
                        }
                        if (values[0].equals("Triangle")) {
                            if ((Double.valueOf(values[1]) + Double.valueOf(values[2])) < Double.valueOf(values[3])) {
                                throw new Exception();
                            } else if ((Double.valueOf(values[2]) + Double.valueOf(values[3])) < Double.valueOf(values[1])) {
                                throw new Exception();
                            } else if ((Double.valueOf(values[3]) + Double.valueOf(values[1])) < Double.valueOf(values[2])) {
                                throw new Exception();
                            }
                        }
                        NoOfObj++;
                    } else {
                        throw new Exception();
                    }
                    } catch (ClassNotFoundException e) {
                    } catch (Exception e) {
                    }
            }
        } catch (IOException e) {
            System.out.println("Unable to read file!");
        }
        shp_obj = new Shape[NoOfObj+2];
        try (BufferedReader buff_r = new BufferedReader(new FileReader(file_N))) {
            NoOfObj = 0;
            while ((temp = buff_r.readLine()) != null) {
                try {
                    String[] values = temp.split(",");
                    if (values[0].equals("Triangle") || values[0].equals("Circle") || values[0].equals("Square") || values[0].equals("Rectangle") ||  values[0].equals("Parallelogram") ) {
                        if (values[0].equals("Triangle")) {
                            if ((Double.valueOf(values[1]) + Double.valueOf(values[2])) < Double.valueOf(values[3])) {
                                throw new Exception("Invalid side");
                            } else if ((Double.valueOf(values[2]) + Double.valueOf(values[3])) < Double.valueOf(values[1])) {
                                throw new Exception("Invalid side");
                            } else if ((Double.valueOf(values[3]) + Double.valueOf(values[1])) < Double.valueOf(values[2])) {
                                throw new Exception("Invalid side");
                            }
                        }
                        switch (values[0]) {
                            case "Circle":
                                shp_obj[NoOfObj] = new Circle(Double.valueOf(values[1]));
                                NoOfObj++;
                                break;
                            case "Parallelogram":
                                shp_obj[NoOfObj] = new Parallelogram(Double.valueOf(values[1]), Double.valueOf(values[2]));
                                NoOfObj++;
                                break;
                            case "Rectangle":
                                shp_obj[NoOfObj] = new Rectangle(Double.valueOf(values[1]), Double.valueOf(values[2]));
                                NoOfObj++;
                                break;
                            case "Square":
                                shp_obj[NoOfObj] = new Square(Double.valueOf(values[1]));
                                NoOfObj++;
                                break;
                            case "Triangle":
                                shp_obj[NoOfObj] = new Triangle(Double.valueOf(values[1]), Double.valueOf(values[2]), Double.valueOf(values[3]));
                                NoOfObj++;
                                break;
                            default:
                                throw new ClassNotFoundException("");
                            }
                    } else {
                        throw new Exception("Invalid side");
                    }
                } catch (ClassNotFoundException e) {   
                    System.out.println(e);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Unable to read file!");
        }
        System.out.println("\n" + NoOfObj + " were created:");
        for (int i = 0; i < NoOfObj; i++)
            System.out.println(shp_obj[i].getClass().getSimpleName() + " {" + shp_obj[i].getDimensions() + "} perimeter = " + String.format("%.2f", shp_obj[i].getPerimeter()));
        
        // Part2     
        System.out.println("\n------->Task 2 ... <-------");
        double small_side = 0;
        double cir_big = 0;
        boolean isTriangle = false;
        for (int i = 0; !isTriangle && (i < shp_obj.length); i++) {
            if (shp_obj[i].getClass().getSimpleName().equals("Triangle")) {
                small_side = shp_obj[i].getPerimeter();
                isTriangle = true;
            }
        }
        // for Circle
        for (int i = 0; i < shp_obj.length; i++) {
            if (shp_obj[i].getClass().getSimpleName().equals("Triangle")) {
                if (shp_obj[i].getPerimeter() < small_side)
                    small_side = shp_obj[i].getPerimeter();
            }
            if (shp_obj[i].getClass().getSimpleName().equals("Circle")) {
                if (shp_obj[i].getPerimeter() > cir_big)
                    cir_big = shp_obj[i].getPerimeter();
            }
        }
        NoOfObj = shp_obj.length;
        for (int i = 0; i < NoOfObj; i++) {
            if (shp_obj[i].getClass().getSimpleName().equals("Triangle")) {
                if(Math.abs(shp_obj[i].getPerimeter() - small_side) <= 0.0){
                    for(int j = i; j < NoOfObj - 1; j++)
                        shp_obj[j] = shp_obj[j + 1];
                    NoOfObj--;
                }
            }
            if (shp_obj[i].getClass().getSimpleName().equals("Circle")) {
                if(Math.abs(shp_obj[i].getPerimeter() - cir_big) <= 0.0){
                    for(int j = i; j < NoOfObj - 1; j++)
                        shp_obj[j] = shp_obj[j + 1];
                    NoOfObj--;
                }
           }
        }
        for (int i = 0; i < NoOfObj; i++)
            System.out.println(shp_obj[i].getClass().getSimpleName() + " {" + shp_obj[i].getDimensions() + "} perimeter = " +  String.format("%.2f",shp_obj[i].getPerimeter()));
        
        // Part 3
        System.out.println("\n------->Task 3 ... <-------");
        double P_Total = 0;
        double T_Total = 0;
        for (int i = 0; i < NoOfObj; i++) {
            if (shp_obj[i].getClass().getSimpleName().equals("Parallelogram"))
                P_Total += shp_obj[i].getPerimeter();
            if (shp_obj[i].getClass().getSimpleName().equals("Triangle"))
                T_Total += shp_obj[i].getPerimeter();
        }
        System.out.println("Total perimeter of Parallelogram is: " +  String.format("%.2f",P_Total));
        System.out.println("Total perimeter of Triangle is: " + T_Total);
    }
}
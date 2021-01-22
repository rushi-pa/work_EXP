package shapes;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class Main {
	public static void main(String[] args) throws ParallelogramException {
		Shape shp_obj[] = new Shape[50];
		int NoOfObject = 0;
		System.out.println("------->Assignment 6<--------");
		try (BufferedReader br = new BufferedReader(new FileReader("shapes/shapes.txt"))) {
			String temp;
			while ((temp = br.readLine()) != null) {
				
				String[] tokens = temp.split(",");
				if (tokens[0].equals("Circle") && tokens.length == 2) {
					try {
						shp_obj[NoOfObject] = new Circle(Double.parseDouble(tokens[1]));
						NoOfObject++;
					} catch (Exception e) {
						System.out.println(e.getMessage());
					}
				}
				else if (tokens[0].equals("Triangle") && tokens.length == 4) {
					try {
						shp_obj[NoOfObject] = new Triangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]), Double.parseDouble(tokens[3]));
						NoOfObject++;
					} catch (Exception e) {
						System.out.println(e.getMessage());
					}
				}
				else if (tokens[0].equals("Square") && tokens.length == 2) {
					try {
						shp_obj[NoOfObject] = new Square(Double.parseDouble(tokens[1]));
						NoOfObject++;
					} catch (Exception e) {
						System.out.println("Invalid side!");
					}
				}
				else if (tokens[0].equals("Parallelogram") && tokens.length == 3) {
					try {
						shp_obj[NoOfObject] = new Parallelogram(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
						NoOfObject++;
					} catch (Exception e) {
						System.out.println(e.getMessage());
					}
				}
				else if (tokens[0].equals("Rectangle") && tokens.length == 3) {
					try {
						shp_obj[NoOfObject] = new Rectangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
						NoOfObject++;
					} catch (Exception e) {
						System.out.println(e.getMessage());
					}
				}
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
		System.out.println();
		System.out.println(NoOfObject + " objects were created:");
		for (int i = 0; i < NoOfObject; i++) {
			System.out.println(shp_obj[i]);
			System.out.println();
		}	
	}
}
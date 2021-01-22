// Name: Ricardo Medeiros - 44
// Seneca Student ID: 135745180
// Seneca email: rmedeiros7@myseneca.ca
// Date of completion: 2020-03-04
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//
// Workshop 6
// ShapeArea.java

package shapes;

/** This class creates ShapeArea interface */
@FunctionalInterface
public interface ShapeArea {
	
	/** 
	 * Creates an abstract method to calculate shape's area
	 * @return a double indicating the area of the shape
	 */
	double calculateArea();
}

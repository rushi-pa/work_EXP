package rmi;
import java.io.Serializable;
public class Car  implements Serializable {
	private int mileage;
	private String plate;
	private String modelNo;
	private String colour;
	
	public Car(){
		this.modelNo = "undefined";
		this.colour = "undefined";
		this.mileage = 0;
		this.plate = "undefined";
	}
	public Car(String modelNo, String colour, int mileage) {
		this.modelNo = modelNo;
		this.colour = colour;
		this.mileage = mileage;
		this.plate = "undefined";
	}
	public String getModel() {
		return this.modelNo;
	}
	public String getColor() {
		return this.colour;
	}
	public int getMileage() {
		return this.mileage;
	}
	public String getPlate() {
		return this.plate;
	}
	public void setModel(String modelNo) {
		this.modelNo = modelNo;
	}
	public void setColor(String colour) {
		this.colour = colour;
	}
	public void setMileage(int mileage) {
		this.mileage = mileage;
	}
	public void setPlate(String plate) {
		this.plate = plate;
	}
	@Override
	public String toString() {
		return "Model: " + getModel() + "\nColor: " + getColor() + "\nMileage: "
				+ getMileage() + "\nPlate: " + getPlate();
	}
}
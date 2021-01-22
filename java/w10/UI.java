package rmi;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.net.MalformedURLException;
import java.rmi.Naming;
public class UI {
	public static void main(String[] args) {
		try {
			
			System.out.println("Fetching new car Info...");
			Car car = new Car("Camry", "lime", 13);
			System.out.println(car.toString());
			System.out.println("\nFetching new Car-Plate...");
			CarInterface obj = (CarInterface) Naming.lookup("rmi://localhost:8080/CreatePlate");
			car.setPlate(obj.registerCar(car));
			System.out.println("\nNew Car-plate No: " + car.getPlate());
			System.out.println("\nRegestring new Car...");
			System.out.println(car.toString());
			
		} catch (MalformedURLException e) {
			System.out.println(e.getMessage());
		} catch (RemoteException e) {
			System.out.println(e.getMessage());
		} catch (NotBoundException e) {
			System.out.println(e.getMessage());
		}
	}
}

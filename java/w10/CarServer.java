package rmi;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
public class CarServer {
	public static void main(String[] args) {
		try {
			CarInterface obj = new plateHash();
			Registry registry = LocateRegistry.createRegistry(8080);
			registry.rebind("CreatePlate", obj);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		System.out.println("Server is up....");
	}
}

package rmi;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
public class plateHash 
extends UnicastRemoteObject 
implements CarInterface {
	public plateHash() throws RemoteException {
		super();
	}
	@Override
	public String registerCar(Car car) throws RemoteException {
		return " " + car.hashCode();
	}
}
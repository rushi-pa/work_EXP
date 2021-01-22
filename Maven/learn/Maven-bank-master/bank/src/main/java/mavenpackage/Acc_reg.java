package mavenpackage;
import java.util.Scanner;
public class Acc_reg {
	public static void Acc_r(){
	db dataConnect = new db();
    dataConnect.connect();
	user in = new user();
	Scanner is = new Scanner(System.in);
	System.out.println("Enter First name");
	in.setFirstName(is.nextLine());
	System.out.println("Enter Last name");
	in.setLastName(is.nextLine());
	System.out.println("Enter Email");
	in.setEmailId(is.nextLine());
	System.out.println("Enter UserId");
	in.setuserId(is.nextLine());
	System.out.println("Enter Password");
	in.setPassword(is.nextLine());
	is.close();
	dataConnect.userData(in);
	}
}
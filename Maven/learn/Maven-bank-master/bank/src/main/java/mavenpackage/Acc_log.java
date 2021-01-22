package mavenpackage;

import java.util.Scanner;

public class Acc_log {
    public Acc_log() throws IllegalAccessException {
        isUsr();
    }
    public static String isUsr() throws IllegalAccessException{
    db dataConnect = new db();
    dataConnect.connect();
    Scanner is = new Scanner(System.in);
	System.out.println("Enter UserId");
    String fname =is.nextLine();
    System.out.println("Enter Password");
    String Pass =is.nextLine();
    try{
    boolean cor = dataConnect.isUser(fname, Pass);
    if(cor){
        System.out.println("Login Successful");
    }else{
        throw new Exception("Incorrect Login attemp");
    }
    }catch(Exception e){
        System.out.println(e);
        isUsr();
    }finally{
    is.close();
    }
    return fname;
    };
}

package mavenpackage;

import java.util.Scanner;

public class ghraphic {
    public static void graphic() {
        System.out.println("If already registered press 1:");
        System.out.println("If new user press 2:");
        Scanner is = new Scanner(System.in);
        String value = is.nextLine();
        try{
        if(value.equalsIgnoreCase("2")){
            try{
            Acc_reg.Acc_r();
            System.out.println("Please Login again");
        }catch(Exception e){
                System.out.println("baba bakchod");
            }finally{
                graphic();
            }
        }else{
           Acc_log.isUsr();
        }}catch(Exception e){
            System.out.println(e);
        }finally{
        is.close();

        }
    }
}

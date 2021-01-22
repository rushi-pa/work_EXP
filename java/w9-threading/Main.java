package multi.threaded;
public class Main {
	public static void main(String[] args) {
		try{
		System.out.println("Part 1:    \n");
		int[] depo = {1, 1, 1, 1, 1, 1};// deposite sequence. pROF EXAMPLE
		String[] curr = {"Dollar(s)", "Euro(s)", "Euro(s)", "Pound(s)", "Pound(s)", "Pound(s)"};// user enters curr to be used 
		//as deposite money
		Account Acc1 = new Account(0, "");
		Thread withdraw = new Withdraw(Acc1, depo);
		Thread deposit = new Deposit(Acc1, depo, curr);
		withdraw.start();
		deposit.start();
		try {
			withdraw.join();
			deposit.join();
		} catch (InterruptedException e) {
			System.out.println(e.getMessage());
		}	}catch(Exception e){
			System.out.println(e);
		}
		
		System.out.println("Part 2:    \n");
			int[] depo = {1, 1, 1, 1, 1, 1 ,1};// deposite sequence. my EXAMPLE
			String[] curr = {"Ruppe(s)", "Rupee(s)", "Rubbles(s)", "Rubbles(s)", "Dinar(s)", "Dinar(s)" ,"Dinar(s)"  }; // user enters curr to be used 
			//as deposite money
			Account Acc1 = new Account(0, "");
			Thread withdraw = new Withdraw(Acc1, depo);
			Thread deposit = new Deposit(Acc1, depo, curr);
			withdraw.start();
			deposit.start();
			try {
				withdraw.join();
				deposit.join();
			} catch (InterruptedException e) {
				System.out.println(e.getMessage());
			}
	}
}
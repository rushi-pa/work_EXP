package multi.threaded;
public class Deposit extends Thread {
	private Account Acc1;
	private int[] amt;
	private String[] currency;
	
	/**
	 * @param Acc1
	 * @param amt
	 * @param currency
	 */
	public Deposit(Account Acc1, int[] amt, String[] currency) {
		this.currency = currency;
		this.Acc1 = Acc1;
		this.amt = amt;
	}
	// overriding the run thread function for custom output
	@Override
	public void run() {
		int i = 0;
		System.out.println("Depositing...\n");
		while (i >= 0 && i < amt.length) {
			synchronized(Acc1) {
				Acc1.deposit(amt[i], currency[i]);
				try {
					if (i < amt.length && i >= 0) i++;
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					System.out.println(e.getMessage());
				}
			}
		}
	}
}
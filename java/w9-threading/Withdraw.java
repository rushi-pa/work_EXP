package multi.threaded;
public class Withdraw extends Thread {
	private Account Acc1;
	private int arr_len;
	/**
	 * @param Acc1
	 * @param deposit
	 */
	public Withdraw(Account Acc1, int[] deposit) {
		this.Acc1 = Acc1;
		this.arr_len = deposit.length;
	}
	@Override
	public void run() {
		System.out.println("Withdrawing...\n");
		for (int i = 0; i < arr_len; i++) {
			synchronized(Acc1) {
				Acc1.withdraw(1);
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					System.out.println(e.getMessage());
				}
				
			}
		}
	}
}

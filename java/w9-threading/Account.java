package multi.threaded;
public class Account {
	private int money;
	private String curr;
	/**
	 * @param money
	 * @param curr
	 */
	Account(int money, String curr) {
		this.money = money;
		this.curr = curr;
	}
	// Deposit money
	public synchronized void deposit(int amt, String curr) {
		while (getBalance() != 0 && getCurrency() != curr) {
			try {
				System.out.println("Invalid currency.\n");
				wait();
			} catch (InterruptedException e) {
				System.out.println(e.getMessage());
			}
		}
		
		if (getCurrency() == curr) {
			setCurrency(curr);
			setBalance(money += amt);
		} else {
			setCurrency(curr);
			setBalance(amt);
		}
		
		System.out.println("Depositing $: " + amt + " " + curr + ".");
		System.out.println("Balance    $: " + getBalance() + " " + getCurrency() + ".\n");
		notify();
	}
	// Synchronized withdrawal
	public synchronized void withdraw(int amt) {
		while (getBalance() < amt) {
			try {
				System.out.println("Incufficient money to withdraw\n");
				wait();
			} catch (InterruptedException e) {
				System.out.println(e.getMessage());
			}
		}
		
		setBalance(getBalance() - amt);
		System.out.println("Withdrawing $: " + amt + " " + getCurrency() + ".");
		System.out.println("Balance     $: " + getBalance() + " " + getCurrency() + ".\n");
		notify();
	}
	public void setBalance(int money) {
		this.money = money;
	}
	public void setCurrency(String curr) {
		this.curr = curr;
	}
	public int getBalance() {
		return this.money;
	}
	public String getCurrency() {
		return this.curr;
	}
}
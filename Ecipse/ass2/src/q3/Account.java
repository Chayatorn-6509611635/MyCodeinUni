package q3;

public class Account {
	private double balance;
	private int accountNumber;
	private static int lastAccountNumber = 0;
	public Account(double intialBalance){
		balance = intialBalance;
		accountNumber = lastAccountNumber + 1;
		lastAccountNumber = accountNumber;
	}
	public void deposit(double depositAmount){
		balance += depositAmount;
	}
	public boolean withdraw(double withdrawAmount){
		if (withdrawAmount > balance){
			System.out.println("Insufficient Funds!!!");
			return false;
		} else {
			balance -= withdrawAmount;
			return true;
		}
	}
	public double getBalance() {
		return balance;
	}
	
	public void display() {
		System.out.println("Balance: " + String.format("%.2f", balance));
		System.out.println("Account No." + accountNumber);
	}
}

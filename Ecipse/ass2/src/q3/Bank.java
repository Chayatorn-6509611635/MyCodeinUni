package q3;

import java.util.ArrayList;

public class Bank {
	private ArrayList<Account> accountList;
	
	public Bank() {
		accountList = new ArrayList<>();
	}
	
	public void addAccount(Account acct) {
		accountList.add(acct);
	}
	
	public Account getAccount(int index) {
		if(index < 0 || index >= accountList.size()) {
			System.err.println("Out of Bound.");
			return null;
		}
		return accountList.get(index);
	}
	
	public ArrayList<Account> findAccounts(double amount){
		ArrayList<Account> account = new ArrayList<>();
		for(Account a: accountList) {
			if(a.getBalance() >= amount) {
				account.add(a);
			}
		}
		if(account.isEmpty()) {
			return null;
		}
		return account;
	}
	
	public Account findMin(){
		Account min = accountList.get(0);
		for(Account a: accountList) {
			if(a.getBalance() < min.getBalance()) {
				min = a;
			}
		}
		return min;
	}
	
	public Account findMax() {
		Account max = accountList.get(0);
		for(Account a: accountList) {
			if(a.getBalance() > max.getBalance()) {
				max = a;
			}
		}
		return max;
	}
	
	public void addInterest() {
		for(Account a: accountList) {
			a.deposit(a.getBalance()*3/100);
		}
	}
	
	public double getTotal() {
		double total = 0;
		for(Account a: accountList) {
			total += a.getBalance();
		}
		return total;
	}
	
	public double getAverage() {
		return getTotal() / accountList.size();
	}
	
	public void displayAll() {
		for(Account a: accountList) {
			a.display();
			System.out.println();
		}
	}
	
	public int getSize() {
		return accountList.size();
	}
}

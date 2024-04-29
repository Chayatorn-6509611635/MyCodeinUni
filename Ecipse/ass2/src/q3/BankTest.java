package q3;

import java.util.Scanner;

public class BankTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Bank b = new Bank();
		
		while(true) {	
			String list;
			System.out.println("What do you want to do?");
			System.out.println("1.) Add account.");
			System.out.println("2.) Account status.");
			System.out.println("3.) Find account.");
			System.out.println("4.) Add Interest.");
			System.out.println("5.) Total balance.");
			System.out.println("Q. Exit program.");
			
			System.out.print("Enter number: ");
			list = sc.next();
			System.out.println();
			
			switch(list) {
			case "1": 
				System.out.print("Enter you balance: ");
				b.addAccount(new Account(sc.nextDouble()));
				break;
				
			case "2":
				int index;
				System.out.print("Enter index (" + 1 + "-" + b.getSize() + "): ");
				index = sc.nextInt();
				if(index > b.getSize() || index < 1) {
					System.err.println("Index out of bound.");
				} else b.getAccount(index-1).display();
				break;
				
			case "3":
				double amount;
				System.out.print("Enter amount: ");
				amount = sc.nextDouble();
				if(b.findAccounts(amount) == null) System.err.println("No account is greater or equal to " + amount);
				else {
					for(Account a: b.findAccounts(amount)) {
						a.display();
						System.out.println();
					}
				}
				
				System.out.println("\nMin account: ");
				b.findMin().display();
				System.out.println("\nMax account: ");
				b.findMax().display();
				break;
				
			case "4":
				b.addInterest();
				b.displayAll();
				break;
				
			case "5":
				System.out.println("Total balance: " + b.getTotal());
				System.out.println("Average balance: " + String.format("%.2f", b.getAverage()));
				break;
				
			case "Q": System.out.println("Exiting program..."); sc.close(); return;
			default : System.err.println("Please type 1-5 or Q...");
			}
			System.out.println();
		}
		
	}
}

package q2;

import java.util.Scanner;

public class TestTellBill {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String tmp;
		while(true) {
			System.out.print("Enter minitues ");
			tmp = sc.nextLine();
			if(tmp.isEmpty()) break;
			double min;
			double cost = 0;
			try {
				min = Double.parseDouble(tmp);
			} catch(Exception e) {
				System.err.println("Can't convert to double");
				continue;
			}
			min = Math.ceil(min);
			if (min <= 0) {
                cost = 0;
            } else if (min < 10) {
                cost = min * 3.5;
            } else if (min <= 20) {
                cost = min * 3;
            } else if (min <= 60) {
                cost = (min - 20) * 1 + 20 * 3;
            } else {
                cost = (min - 60) * 1.5 + (60 - 20) * 1 + 20 * 3;
            }
			System.out.println("You have to pay " + cost);
		}
		sc.close();
	}
}

package q1;

import java.util.Scanner;

public class Roman {
	
	@SuppressWarnings("resource")
	public static String setRoman() {
		String s;
		System.out.print("Input the roman number ");
		Scanner sc = new Scanner(System.in);
		s = sc.next();
		return s;
	}
	
	public static String convertRoman(String s) {	
		String result = "It is ";
		switch(s) {
			case "I": result += "One"; break;
			case "II": result += "Two"; break;
			case "III": result += "Three"; break;
			case "IV": result += "Four"; break;
			case "V": result += "Five"; break;
			case "VI": result += "Six"; break;
			default: result = "Unknown Number"; break;
		}
		return result+='.';
	}
	

}

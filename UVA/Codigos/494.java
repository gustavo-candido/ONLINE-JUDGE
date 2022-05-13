import java.util.*;
import java.math.*;


class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s;
		
		while(sc.hasNext()) {
			s = sc.nextLine();
			System.out.printf("%d\n", s.replaceAll("[^a-zA-Z]+", " ").trim().split(" ").length);
		}
	}
}

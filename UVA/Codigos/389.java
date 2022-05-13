import java.util.*;
import java.math.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b;
		String num, ans;
		
		while(sc.hasNext()) {
			num = sc.next();
			a = sc.nextInt();
			b = sc.nextInt();
			BigInteger B = new BigInteger(num, a);
			ans = B.toString(b);
			if(ans.length() > 7) System.out.println("  ERROR");
			else System.out.printf("%7s\n", ans.toUpperCase());
		}
	}
}

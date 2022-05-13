import java.util.*;
import java.math.*;

class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String x;
		int n;
		BigInteger p = BigInteger.ZERO, q = BigInteger.ZERO, z;
		n = sc.nextInt();
		for(int i=0; i<n; i++) {
			p = sc.nextBigInteger();
			x = sc.next();
			q = sc.nextBigInteger();
			z = p.gcd(q);
			System.out.printf("%s / %s\n", p.divide(z), q.divide(z));
		}
	}
}

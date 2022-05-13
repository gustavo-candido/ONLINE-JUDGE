import java.util.*;
import java.math.*;

class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int c;
		BigInteger z, x, y, n;
		while(sc.hasNext()) {
			c = sc.nextInt();
			if(c==0) break;
			for(int i=0; i<c; i++) {
				x = sc.nextBigInteger();
				y = sc.nextBigInteger();
				n = sc.nextBigInteger();
				z = x.modPow(y, n);
				System.out.printf("%s\n", z);
			}
		}
	}
}

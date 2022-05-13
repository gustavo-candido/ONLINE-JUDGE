import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		BigInteger p, a;
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()) {
			p = sc.nextBigInteger();
			a = sc.nextBigInteger();
			if(p.compareTo(a) == 0 && p.compareTo(BigInteger.valueOf(0)) == 0)break;
			if(p.isProbablePrime(10) == false && a.modPow(p,p).compareTo(a) == 0) System.out.printf("yes\n");
			else System.out.printf("no\n");
		}
	}
}

import java.util.*;
import java.math.*;

public class Main{
	public static void main (String[] args) {
		BigInteger BI = BigInteger.ZERO;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			BI = sc.nextBigInteger();
			if(BI.isProbablePrime(10)) {
				String a = BI.toString();
				String b = new StringBuffer(BI.toString()).reverse().toString();
				BigInteger BII = new BigInteger(b);
				if (a.equals(b) == true) System.out.printf("%s is prime.\n", a);
				else if(BII.isProbablePrime(10)) System.out.printf("%s is emirp.\n", a);
				else System.out.printf("%s is prime.\n", a);
			} 
			else System.out.printf("%s is not prime.\n", BI);
		}
	}
}

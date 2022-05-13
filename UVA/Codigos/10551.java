import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int b;
		BigInteger p = BigInteger.ZERO, m = BigInteger.ZERO;
		
		while(sc.hasNext()) {
			b = sc.nextInt();
			if(b==0) break;
			p = sc.nextBigInteger(b);
			m = sc.nextBigInteger(b);
			p = p.remainder(m);
			System.out.println(p.toString(b));
		} 
	}
	
}

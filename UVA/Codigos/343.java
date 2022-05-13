import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		BigInteger A = new BigInteger("0"), B = new BigInteger("0");
		String a, b;
		int x=0, y=0;
		boolean base;
		while(sc.hasNext()) {
			base = false; 
			a = sc.next();
			b = sc.next();
			
			for(int i=2; i<37; i++) {
				try {
					A = new BigInteger(a, i);
				}
				catch(Exception e) {
					continue;
				}
				for(int j=2; j<37; j++) {
					try {
						B = new BigInteger(b, j);
					}
					catch(Exception e) {
						continue;
					}	  
				    if(A.compareTo(B) == 0) {
						x = i;
						y = j;
						base = true;
						break;
					}
				}
				if(base) break;
			}
			if(base == true) {
				System.out.printf("%s (base %d) = %s (base %d)\n", a, x, b, y);
				//System.out.println(A + " (base " + x + ") = " + B + " (base " + y + ")");
			}
			else {
				System.out.printf("%s is not equal to %s in any base 2..36\n", a, b);
			}
		}
	}
}

import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n;
		BigInteger[] f = new BigInteger[605];
		BigInteger[] cat = new BigInteger[305];
		f[0] = BigInteger.ONE;
		for(int i=1; i<=600; i++) {
			f[i] = f[i-1].multiply(BigInteger.valueOf(i));
		}
		for(int i=1; i<=300; i++) {
			cat[i] = f[2*i].divide(f[2*i-i].multiply(f[i])).divide(BigInteger.valueOf(i+1));
		}
		while(sc.hasNext()) {
			n = sc.nextInt();
			if(n == 0) break;
			System.out.printf("%s\n", cat[n].multiply(f[n]));
		}
	}
	
}

import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n;
		boolean blank_line=false;
		BigInteger[] f = new BigInteger[30];
		BigInteger[] cat = new BigInteger[11];
		f[0] = BigInteger.ONE;
		for(int i=1; i<30; i++) {
			f[i] = f[i-1].multiply(BigInteger.valueOf(i));
		}
		for(int i=1; i<11; i++) {
			cat[i] = f[2*i].divide(f[2*i-i].multiply(f[i])).divide(BigInteger.valueOf(i+1));
		}
		while(sc.hasNext()) {
			n = sc.nextInt();
			if(blank_line) System.out.printf("\n");
			System.out.printf("%s\n", cat[n]);
			blank_line = true;
		}
	}
	
}

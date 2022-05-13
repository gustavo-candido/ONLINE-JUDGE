import java.util.*;
import java.math.*;

public class Main {
	public static void main (String[] args) {
		Scanner ent = new Scanner(System.in);
		BigInteger big = new BigInteger("0");
		int N, A;
		
		while(ent.hasNextInt()) {
			N = ent.nextInt();
			A = ent.nextInt();
			big = BigInteger.valueOf(0);
			for(int i=1; i<=N; i++) {
				big = big.add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(A).pow(i)));
			}
			System.out.println(big);
		}
	}
	
}

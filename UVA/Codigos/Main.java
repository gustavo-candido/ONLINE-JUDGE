import java.util.*;
import java.math.*;


class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger B, P, M;
		
		while(sc.hasNext()) {
			B = sc.nextBigInteger();
			P = sc.nextBigInteger();
			M = sc.nextBigInteger();
			
			System.out.printf("%s\n", B.modPow(P,M));
		} 
	}
}

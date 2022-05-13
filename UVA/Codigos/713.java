import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N;
		BigInteger A = new BigInteger("0"), B = new BigInteger("0");
		String X, Y;
		N = sc.nextInt();
		
		for(int i =0; i<N; i++) {
			A = sc.nextBigInteger();
			B = sc.nextBigInteger();
			X = new StringBuffer(A.toString()).reverse().toString();
			Y = new StringBuffer(B.toString()).reverse().toString();
			A = new BigInteger(X);
			B = new BigInteger(Y);
			A = A.add(B);
			X = new StringBuffer(A.toString()).reverse().toString();
			A = new BigInteger(X);
			System.out.println(A);
		}
	}
}

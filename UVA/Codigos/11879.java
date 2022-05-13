import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger n = new BigInteger("0");
		
		while(true) {
			n = sc.nextBigInteger();
			if(n.equals(new BigInteger("0")) == true) break;
			if((n.remainder(new BigInteger("17"))).equals(new BigInteger("0")))System.out.println(1);
			else System.out.println(0);
		}
	}
}

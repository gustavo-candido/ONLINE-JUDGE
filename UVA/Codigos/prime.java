import java.util.*;
import java.math.*;

public class source {
	public static void main(String[] args) {
		BigInteger BI = BigInteger.ZERO;
		
		while(BI.compareTo(BigInteger.valueOf(100000000)) != 1) {
			BI = BI.nextProbablePrime();
			System.out.printf("%s, ", BI);
		}
	}
}

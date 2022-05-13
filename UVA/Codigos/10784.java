import java.util.*;
import java.math.*;

class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger N;
		int f, i=1;
		while(sc.hasNext()) {
			N = sc.nextBigInteger();
			if(N.compareTo(BigInteger.valueOf(0)) == 0) break;
			
			BigInteger l = BigInteger.ONE, r = new BigInteger("44721362"), mid = BigInteger.ZERO, n, z;
			boolean x = true;
			while(x == true && l.compareTo(r) != 1) {
				mid = l.add(r).divide(new BigInteger("2"));
				n = mid.multiply(mid.subtract(new BigInteger("3"))).divide(new BigInteger("2"));
				if(n.compareTo(N) == 1) {
					z = mid.subtract(new BigInteger("1")).multiply(mid.subtract(new BigInteger("1")).subtract(new BigInteger("3"))).divide(new BigInteger("2"));
					if(z.compareTo(N) == 0) {
						x = false;
						mid = mid.subtract(new BigInteger("1"));
					}
					else if(z.compareTo(N) == -1) x = false;
					r = mid.subtract(BigInteger.ONE);
				}
				else if(n.compareTo(N) == -1) l = mid.add(BigInteger.ONE);
				else x=false;
			}
			
			System.out.printf("Case %d: %s\n", i,mid);
			i++;
		}
	}
}

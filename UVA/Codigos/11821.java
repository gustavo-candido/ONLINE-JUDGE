import java.util.*;
import java.math.*;

class Main  {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, count=0;
		BigDecimal b, sum = new BigDecimal("0");
		n = sc.nextInt();
		
		while(count != n) {
			b = new BigDecimal(sc.next());
			if(b.compareTo(new BigDecimal("0")) == 0) {
				count++;
				System.out.println(sum.stripTrailingZeros().toPlainString());
				sum = new BigDecimal("0");
			}
			sum = sum.add(b);
		}
		
	}
	
}

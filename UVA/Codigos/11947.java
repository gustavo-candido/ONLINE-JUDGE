	 import java.util.*;
	 
	 class Main {
		 public static void main (String[] args) {
			 Scanner cin = new Scanner(System.in);
			 Calendar cal = Calendar.getInstance();
			 int N, D, M, Y;
			 char[] str;
			 N = cin.nextInt();
			 for(int c=0; c<N; c++) {
				 str = cin.next().toCharArray();
				 M = (((int)str[0] - 48) * 10) + (((int)str[1] - 48));
				 D = (((int)str[2] - 48) * 10) + (((int)str[3] - 48));
				 Y = (((int)str[4] - 48) * 1000) + (((int)str[5] - 48) * 100) + (((int)str[6] - 48) * 10) + (((int)str[7] - 48));
				 cal.set(Y, M-1, D);
				 cal.add(Calendar.DATE, 40*7);
				 System.out.printf("%d ", c+1);
				 M = cal.get(Calendar.MONTH)+1;
				 D = cal.get(Calendar.DATE);
				 if(M < 10) System.out.printf("0%d/", 1+cal.get(Calendar.MONTH));
				 else System.out.printf("%d/", 1+cal.get(Calendar.MONTH));
				 if(D < 10) System.out.printf("0%d/", 1+cal.get(Calendar.DATE));
				 else System.out.printf("%d/", 1+cal.get(Calendar.DATE));
				 System.out.printf("%d ", cal.get(Calendar.YEAR));
				 if(M==1 && D>=21 || M==2 && D <=19) System.out.printf("aquarius\n");
				 else if (M==2 && D>=20 || M==3 && D <=20) System.out.printf("pisces\n");
				 else if (M==3 && D>=21 || M==4 && D <=20) System.out.printf("aries\n");
				 else if (M==4 && D>=21 || M==5 && D <=21) System.out.printf("taurus\n");
				 else if (M==5 && D>=22 || M==6 && D <=21) System.out.printf("gemini\n");
				 else if (M==6 && D>=22 || M==7 && D <=22) System.out.printf("cancer\n");
				 else if (M==7 && D>=23 || M==8 && D <=21) System.out.printf("leo\n");
				 else if (M==8 && D>=22 || M==9 && D <=23) System.out.printf("virgo\n");
				 else if (M==9 && D>=24 || M==10 && D <=23) System.out.printf("libra\n");
				 else if (M==10 && D>=24 || M==11 && D <=22) System.out.printf("scorpio\n");
				 else if (M==11 && D>=23 || M==12 && D <=22) System.out.printf("sagittarius\n");
				 else if (M==12 && D>=23 || M==1 && D <=20) System.out.printf("capricorn\n");
			
			 }
		 }
	 }

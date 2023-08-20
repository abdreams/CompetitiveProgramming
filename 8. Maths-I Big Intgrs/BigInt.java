import java.math.BigInteger;
import java.util.Scanner;

public class BigInt // class name to be same as filename
{
	static void playwithbigint(){
		Scanner sc = new Scanner(System.in);

		String s1 = sc.next();

		BigInteger b1=new BigInteger(s1);
		BigInteger b2=new BigInteger("12321798327132791732");

		//b1=b1.add(b2);
		//multiply
		b1=b1.multiply(b2);
		System.out.println(b1);

		//count number of set bits
		System.out.println(b1.bitCount());

		//total no of bits
		System.out.println(b1.bitLength());

		//integer to big integer
		int a=sc.nextInt();
		int b=sc.nextInt();

		System.out.println(a+b);

		BigInteger b3= BigInteger.valueOf(a);
		BigInteger b4= BigInteger.valueOf(b);

		System.out.println(b3.gcd(b4));

		// base conversion

		BigInteger b5= new BigInteger("1001",2);
		System.out.println(b5);

		// power of biginteger, we can take power of bigint as int only

		System.out.println(b3.pow(20));


	}
	
	static BigInteger factorial(int N)
	{
		BigInteger f = new BigInteger("1"); // Or BigInteger.ONE

		for (int i = 2; i <= N; i++)
			f = f.multiply(BigInteger.valueOf(i));

		return f;
	}

	public static void main(String args[]) 
	{
		
		int N = 20;
		System.out.println(factorial(N));
		playwithbigint();
	}
}

public class precisao{
	public static double A=1;
	public static double s=2;
	public static double prec;

	public static void main(String[] args){
		while(s>1){
			A = A/2;
			s = 1+A;
		}

		prec = 2*A;
		System.out.println(prec);
	}
}

class Number{
	static int a,b;
	{
		a=100;
		System.out.println("a=100");
	}
	static{
		a=10;
		b=100;
		System.out.println("a=10,b=100");
	}
}
class Triangle{
	public static void main(String[] args){
		Number n = new Number();
	}
}
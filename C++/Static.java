public class Static{
	static{
		int x=5;
	}
	static int x,y;
	public static void main(String[] args){
		x--;
		System.out.println(x);
		myMethod();
		System.out.println(x);
		System.out.println(y);
		System.out.println(x+y+ ++x);
	}
	public static void myMethod(){
		y=x++ + ++x;
	}
}
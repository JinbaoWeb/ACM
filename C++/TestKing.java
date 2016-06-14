public class TestKing{

	public static void go(short n){System.out.println("short");}
	public static void go(short n){System.out.println("SHORT");}
	public static void go(long n){System.out.println("long");}
	public static void main(String[] args){
		go(6);
		go(7L);
	}
}
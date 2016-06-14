import java.util.*;
class TestArray{
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int n;
		int[][] a = new int[100][100];
		String[] b = new String[100];
		while (input.hasNext()){
			n = input.nextInt();
			for (int i = 0 ; i < n ; i ++ )
				for (int j = 0 ; j < n ; j ++ )
					a[i][j] = input.nextInt();	//input a array
			for (int i = 0 ; i < n ; i ++ )
				b[i] = input.next();
			System.out.println();
			for (int i = 0 ; i < n ; i ++ ){
				for (int j = 0 ; j < n ; j ++ )
					System.out.print(a[i][j] + " ");
				System.out.println();
			}
			System.out.println();
			for (int i = 0 ; i < n ; i ++ ){
				System.out.println(b[i]);
			}
		}
	}
}
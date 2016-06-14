class Calculate{
	public static int calculate_1(){
		int i = 1 , sum = 0;
		while (i <= 100){
			sum += i ++;
		}
		return sum;
	}
	public static int calculate_2(){
		int sum = 0;
		for (int i = 0 ; i < 101 ; i ++)
			sum += i;
		return sum;
	}
	public static int calculate_3(){
		int sum = 0, i = 1;
		do{
			sum += i;
		}while (i > 100);
		return sum;
	}
	public static void main(String []args){
		System.out.println("Using while to calculate the sum of 1 to 100 , the answer is : " + calculate_1());
		System.out.println("Using for to calculate the sum of 1 to 100 , the answer is : " + calculate_2());
		System.out.println("Using do-while to calculate the sum of 1 to 100 , the answer is : " + calculate_1());
	}
}
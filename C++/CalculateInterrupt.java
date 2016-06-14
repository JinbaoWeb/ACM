class CalculateInterrupt{
	public static void main(String[] args){
		for (int i=1;i<=100;i++){
			if (i==78){
				System.out.println("Interrupt!");
				break;
			}
		}
	}
}
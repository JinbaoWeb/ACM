class TestModify{
	public static void modify(){
		int i,j,k;
		i=0;
		k=0;
		while (i<10){
			j = ++i * 2;
			System.out.println("the value of j is " + j );
			k = k + 1;
		}
	}
	public static void main(String[] args){
		modify();
		boolean a = true,b = false, c = true;
		if (a==true)
			if (b==true)
				if (c==true)	System.out.println("01");
				else System.out.println("02");
			else if (a&&(b=c)) System.out.println("03");
			else System.out.println("04");
	}
}
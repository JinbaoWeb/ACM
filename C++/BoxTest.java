import java.util.*;
class Box{
	int wide,high,lenth;
	public void setDemo(int w,int l,int h){
		wide = w;
		high = h;
		lenth = l;
	}
	public int CalculateVolume(){
		return wide * high * lenth;
	}
}
class BoxTest{
	public static void main(String[] args){
		int w,l,h;
		Scanner input = new Scanner(System.in);
		while (input.hasNext()){
			w = input.nextInt();
			l = input.nextInt();
			h = input.nextInt();
			Box b = new Box();
			b.setDemo(w,l,h);
			System.out.println("The volume of box is : " + b.CalculateVolume());
		}
	}
}
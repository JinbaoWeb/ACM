import java.util.*;
import java.math.*;
interface Area{
	int calculateArea();
}
class MyCircle{
	private double r;
	public MyCircle(double r){
		this.r = r;
	}
	public double calculateArea(){
		return Math.PI * r * r;
	}
}
class MyRectangle{
	private int width,length;
	public MyRectangle(int w,int l){
		width = w;
		length = l;
	}
	public int calculateArea(){
		return width * length;
	}
}
class TestArea{
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		double r = input.nextDouble();
		MyCircle circle = new MyCircle(r);
		System.out.println("circle's area is " + circle.calculateArea());
		int w = input.nextInt();
		int l = input.nextInt();
		MyRectangle rectangle = new MyRectangle(w,l);
		System.out.println("rectangle's area is " + rectangle.calculateArea());
	}
}
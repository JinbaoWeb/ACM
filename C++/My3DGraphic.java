import java.math.*;
interface I{
	float calArea();
	float calVolume();
}
class My3DGraphic{
	private String surfaceColor;
	private String fillColor;
	My3DGraphic(String s,String f){
		surfaceColor = s;
		fillColor = f;
	}
	public void print(){
		System.out.println("surfaceColor = " + surfaceColor + " fillColor = " + fillColor);
	}
	public static void main(String[] args){
		Mycube cube = new Mycube(5f,"black","white");
		MySphere sphere = new MySphere(5f,"red","blue");
		System.out.print("cube : ");
		cube.print();
		System.out.println("cube's calArea = " + cube.calArea() + " and calVolume = " + cube.calVolume());
		System.out.print("sphere : ");
		sphere.print();
		System.out.println("sphere's calArea = " + sphere.calArea() + " and calVolume = " + sphere.calVolume());
	}
}
class Mycube extends My3DGraphic implements I{
	private float rLong;
	Mycube(float r,String s,String f){
		super(s,f);
		rLong = r;
	}
	public float calVolume(){
		return rLong * rLong * rLong;
	}
	public float calArea(){
		return 6 * rLong * rLong;
	}
}
class MySphere extends My3DGraphic implements I{
	private float radius;
	MySphere(float r,String s,String f){
		super(s,f);
		radius = r;
	}
	public float calVolume(){
		return 4f / 3f * radius * radius * radius * (float)Math.PI;
	}
	public float calArea(){
		return 4f * (float)Math.PI * radius * radius;
	}
}
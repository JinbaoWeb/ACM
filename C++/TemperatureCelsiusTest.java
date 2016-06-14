import java.util.Scanner;
class TemperatureCelsius{
	private double degree;
	public TemperatureCelsius(double d){
		this.degree = d;
	}
	public double toFahrenheit(){
		return (degree * 9/5) + 32;
	}
}
public class TemperatureCelsiusTest{
	public static void main(String []args){
		Scanner input = new Scanner(System.in);
		double d = input.nextDouble();
		TemperatureCelsius celsius = new TemperatureCelsius(d);
		System.out.println(celsius.toFahrenheit());
	}
}
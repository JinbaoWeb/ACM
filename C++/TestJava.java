
class Vehicle{
	private int wheels,weight;
	public int getWheels(){
		return wheels;
	}
	public int getWeight(){
		return weight;
	}
}
class Car extends Vehicle{
	private int passenger_load;
	public int getPassenger_load(){
		return passenger_load;
	}
}
class Truck extends Vehicle{
	private int passenger_load,payload;
	public int getPassenger_load(){
		return passenger_load;
	}
	public int getPayload(){
		return payload;
	}
}
public class TestJava{
	public static void main(String []args){
		Truck truck = new Truck();
		
		System.out.println("Truck's passenger_load is " + truck.getPassenger_load() + " Truck's payload is " + truck.getPayload());
		Vehicle vehicle = new Vehicle();
		System.out.println("Vehicle's wheels is " + vehicle.getWheels() + " Vehicle's weight is " + vehicle.getWeight());
		Car car = new Car();
		System.out.println("Car's passenger_load is " + car.getPassenger_load());
	}
}
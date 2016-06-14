interface FlyBehavior{
	public void fly();
}
class FlyWithWings implements FlyBehavior{
	public void fly(){
		System.out.println("I'm flying!");
	}
}
class FlyNoWay implements FlyBehavior{
	public void fly(){
		System.out.println("I can't fly!");
	}
}

interface QuackBehavior{
	public void quack();
}
class Quack implements QuackBehavior{
	public void quack(){
		System.out.println("Quack!");
	}
}
class MuteQuack implements QuackBehavior{
	public void quack(){
		System.out.println("Silence!");
	}
}
class Squeak implements QuackBehavior{
	public void quack(){
		System.out.println("Squeak!");
	}
}

abstract class Duck {
    FlyBehavior flyBehavior;
    QuackBehavior quackBehavior;
    public Duck() {}
    abstract void display();
    public void performFly() {
        flyBehavior.fly();
    }
    public void performQuack() {
        quackBehavior.quack();
    } 
    public void swim() {
        System.out.println("All ducks float, even decoys!");
    }
}

class MallardDuck extends Duck{
	public MallardDuck(){
		quackBehavior = new Quack();
		flyBehavior = new FlyWithWings();
	}
	public void display(){
		System.out.println("I'm a real Mallard duck!");
	}
}

public class TestDuck{
	public static void main(String[] args){
		Duck mallard = new MallardDuck();
		mallard.performQuack();
		mallard.performFly();
	}
}
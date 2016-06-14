class SuperClass{
	int x;
	void method0(){
		System.out.println("11111111111111");
		method2();
	}
	void method2(){
		x=11;
		System.out.println("222222222222222");
	}
}
class SubClass extends SuperClass{
	int x;
	void method2(){
		x=2;
		System.out.println("3333333333333333333");
	}
	public static void main(String[] args){
		SubClass rSub = new SubClass();
		SuperClass rSuper = rSub;
		SuperClass r = new SuperClass();
		r.method0();
		rSub.method0();
		rSuper.method0();
		System.out.println(rSuper.x + " , " + rSub.x);
	}
}
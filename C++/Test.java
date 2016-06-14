class Body{
	public long idNum;
	public String name = "<unnamed>";
	public Body orbits = null;
	private static long nextID = 0;
	{
		idNum = nextID++;
	}
	public Body(String bodyName,Body orbitsAround){
		name = bodyName;
		orbits = orbitsAround;
	}

}
class Test{

	public static void main(String []args){
		Body earth = new Body("earth",null);
		Body yueliang = new Body("yueliang",earth);
		System.out.println(earth.idNum + yueliang.idNum);
	}
}
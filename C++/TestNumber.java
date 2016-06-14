class Number{
	private int row,column,value;
	public Number(int r,int c,int v){
		row = r;
		column = c;
		value = v;
	}
	public int getRow(){
		return row;
	}
	public int getColumn(){
		return column;
	}
	public int getValue(){
		return value;
	}
}
class TestNumber{
	public static void main(String[] args){
		Number num[][] = new Number[5][];
		for (int i = 0;i < 5;i ++){
			num[i] = new Number[i+1];
			for (int j = 0;j <= i;j ++){
				num[i][j] = new Number(i,j,j);
			}
		}
		for (int i = 0 ; i < num.length ; i ++ ){
			for (int j = 0 ; j < num[i].length ; j ++ ){
				System.out.printf("(%d,%d:%d)",num[i][j].getRow(),num[i][j].getColumn(),num[i][j].getValue());
			}
			System.out.println();
		}
	}
	

}
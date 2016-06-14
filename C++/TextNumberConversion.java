package com.zf.s2;	//创建一个包
import java.util.Scanner;	
public class TextNumberConversion{	//操作数制转换的类

	public static int NumberToTen(int beforeConversion,String number){	//其他进制转成十进制
		double result = 0;	//声明转换后的数值
		String subString;	
		for (int i = 0; i < number.length(); i++){	//根据字符串的长度循环获得单个元素
			subString = number.substring(i , i+1);	//将字符串按循环截取
			if (beforeConversion == 16){	//判断是否是十六进制
				subString = sixteenCharToNumber(subString);	//将字母转化为数字
			}
			result += Integer.parseInt(subString) * Math.pow(beforeConversion,number.length() - i - 1);	
		}
		return (int) result;	//返回转换的结果
	}

	public static String TenToNumber(int afterConversion,String number){	//十进制转成其他进制
		int current = Integer.parseInt(number);	//将字符转换成整数
		String opResult = "";
		if (afterConversion == 16){	//判断转换后的进制是否是十六进制
			while (current >= afterConversion){	//判断传入的数是否大于16，大于则逢16进
				opResult += sixteenNumberToChar(current % afterConversion);	//将数字转换成字母
				current /= afterConversion;
			}
			if (current != 0)	//最终余数
				opResult +=sixteenNumberToChar(current);	
		}
		else{
			while (current >= afterConversion){	//判断传人的值是否大于转换后的进制
				opResult += current % afterConversion;
				current /= afterConversion;
			}
			if (current != 0){	//最终余数
				opResult += current;
			}
		}
		String riResult = "";	//倒序二进制字符串
		for (int i = opResult.length() - 1;i >= 0; i--){	//根据二进制的转换方式进行循环输出
			riResult += opResult.substring(i,i + 1);
		}
		return riResult;
	}

	public static String sixteenCharToNumber(String s){	//十六进制字母对应数字
		String num = "";
		if (s.equals("A") || s.equals("a"))
			num = "10";
		else if (s.equals("B") || s.equals("b"))
			num = "11";
		else if (s.equals("C") || s.equals("c"))
			num = "12";
		else if (s.equals("D") || s.equals("d"))
			num = "13";
		else if (s.equals("E") || s.equals("e"))
			num = "14";
		else if (s.equals("F") || s.equals("f"))
			num = "15";
		else
			num = s;
		return num;
	}

	public static String sixteenNumberToChar(int num){	//十六进制数字对应字母
		String c = "";
		if (num == 10)
			c = "A";
		else if (num == 11)
			c = "B";
		else if (num == 12)
			c = "C";
		else if (num == 13)
			c = "D";
		else if (num == 14)
			c = "E";
		else if (num == 15)
			c = "F";
		else
			c = String.valueOf(num);
		return c;
	}

	public static void main(String []args){
		String number;
		int beforeConversion,afterConversion;
		String result = "";
		String stop = "";
		Scanner read = new Scanner(System.in);
		do{
			System.out.println("请输入三个参数（整数）：");
			System.out.println("待转换的数据：");
			number = read.next();
			System.out.println("转换前的数制：");
			beforeConversion = read.nextInt();
			System.out.println("转换后的数制：");
			afterConversion = read.nextInt();
			stop = "Q";
		}while (stop != "Q");
		try{
			if (beforeConversion != 10){
				String temp = String.valueOf(NumberToTen(beforeConversion,number));
				result = String.valueOf(TenToNumber(afterConversion,temp));
			}
			else{
				result = String.valueOf(TenToNumber(afterConversion,number));
			}
			System.out.println(beforeConversion + "进制的数： " + number + " 转换成 " + afterConversion + "进制的数为： " + result);
		}catch (Exception e){
			System.out.println("转换失败，请输入合法的数据！");
			System.exit(-1);
		}
	}
}
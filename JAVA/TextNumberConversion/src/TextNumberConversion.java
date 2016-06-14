//package com.zf.s2;	//����һ����
import java.util.Scanner;	
public class TextNumberConversion{	//��������ת������

	public static int NumberToTen(int beforeConversion,String number){	//��������ת��ʮ����
		double result = 0;	//����ת�������ֵ
		String subString;	
		for (int i = 0; i < number.length(); i++){	//�����ַ����ĳ���ѭ����õ���Ԫ��
			subString = number.substring(i , i+1);	//���ַ�����ѭ����ȡ
			if (beforeConversion == 16){	//�ж��Ƿ���ʮ������
				subString = sixteenCharToNumber(subString);	//����ĸת��Ϊ����
			}
			result += Integer.parseInt(subString) * Math.pow(beforeConversion,number.length() - i - 1);	
		}
		return (int) result;	//����ת���Ľ��
	}

	public static String TenToNumber(int afterConversion,String number){	//ʮ����ת����������
		int current = Integer.parseInt(number);	//���ַ�ת��������
		String opResult = "";
		if (afterConversion == 16){	//�ж�ת����Ľ����Ƿ���ʮ������
			while (current >= afterConversion){	//�жϴ�������Ƿ����16���������16��
				opResult += sixteenNumberToChar(current % afterConversion);	//������ת������ĸ
				current /= afterConversion;
			}
			if (current != 0)	//��������
				opResult +=sixteenNumberToChar(current);	
		}
		else{
			while (current >= afterConversion){	//�жϴ��˵�ֵ�Ƿ����ת����Ľ���
				opResult += current % afterConversion;
				current /= afterConversion;
			}
			if (current != 0){	//��������
				opResult += current;
			}
		}
		String riResult = "";	//����������ַ���
		for (int i = opResult.length() - 1;i >= 0; i--){	//���ݶ����Ƶ�ת����ʽ����ѭ�����
			riResult += opResult.substring(i,i + 1);
		}
		return riResult;
	}

	public static String sixteenCharToNumber(String s){	//ʮ��������ĸ��Ӧ����
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

	public static String sixteenNumberToChar(int num){	//ʮ���������ֶ�Ӧ��ĸ
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
			System.out.println("������������������������");
			System.out.println("��ת�������ݣ�");
			number = read.next();
			System.out.println("ת��ǰ�����ƣ�");
			beforeConversion = read.nextInt();
			System.out.println("ת��������ƣ�");
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
			System.out.println(beforeConversion + "���Ƶ����� " + number + " ת���� " + afterConversion + "���Ƶ���Ϊ�� " + result);
		}catch (Exception e){
			System.out.println("ת��ʧ�ܣ�������Ϸ������ݣ�");
			System.exit(-1);
		}
	}
}
package com.pat.basic;

import java.util.Scanner;

public class P1002 {
	public static  void  func(){
		String index[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
		Scanner scanner = new Scanner(System.in);
		String str = scanner.nextLine();
		int sum = 0;
		//求得各个位数之和
		for(int i = 0; i < str.length(); i++){
			sum += str.charAt(i)-'0';
		}
		//将整形转为字符串
		String result = ""+sum;
		//System.out.println(result);
		for(int i = 0; i < result.length(); i++){
			if( i == result.length() -1)
				System.out.print(index[result.charAt(i)-'0']);
			else
				System.out.print(index[result.charAt(i)-'0']+" ");
		} 
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		P1002.func();
	}

}

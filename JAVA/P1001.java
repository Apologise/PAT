package com.pat.basic;

import java.util.Scanner;

public class P1001 {
	public static int func(int num){
		int steps = 0;
		while(num > 1){
			if(num%2 == 0){
				num /= 2; 
				steps ++;
			}else{
				num = (3*num+1)/2;
				steps ++;
			}
		}
		return steps;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner src = new Scanner(System.in);
		int num = Integer.parseInt(src.nextLine());
		System.out.println(P1001.func(num));
	}

}

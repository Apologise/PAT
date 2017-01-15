/*
Author:Apolo
Time : 2017-01-14 
Problem Description�������ı�ʾ�ͻ��� 
Method�����ڷ����ĳ˷��ͳ��������п���ʹ���ӻ��ĸ����int�ͱ�ʾ��Χ�����һ�������
		�����Ӻͷ�ĸӦ��ʹ��long long�洢 
*/
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;

struct Fraction{
	int up, down;
};

//�����Ļ���
Fraction reduction(Fraction result){
	if(result.down < 0){
		result.up = - result.up;
		result.down = - result.down;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up, abs(result.down)));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

//�����ļӷ� 
Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.down + f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}

//�����ļ���
Fraction sub(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.down - f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}

//�����ĳ˷�
Fraction mul(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);	
}

//�����ĳ���
Fraction divide(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);	
}

//��������� 
1.�����ĸΪ1����ôֱ���������
2.������ӵľ���ֵ���ڷ�ĸ����Ϊ�ٷ����������ӳ��Է�ĸ����������Ϊ���� 
3.ֱ��������� 
void showResult(Fraction r){
	if(r.down == 1){
		printf("%lld",r.up);
	} else if(abs(r.up) > r.down){	//	�����ʱ�������ĸΪ���������Ż���ȥ�����Բ���Ҫ�����ֵ 
		printf("%d %d/%d", r.up, abs(r.up) % r.down, r.down);
	}else{
		printf("%d/%d", r.up, r.down);
	}
} 
 


/*
Author:Apolo
Time : 2017-01-14 
Problem Description�������Լ�� 
Method���ݹ������Լ���������ö���֤��a,b�����Լ����b��a/b�����Լ����� ,�������
		0�������Լ����a 
*/ 

int gcd(int a, int b){
	if(a == 0){
		return a;
	}else{
		return gcd(b, a % b);	//	��a,b���� 
	}	
} 

//��С�������ǣ�ab/gcd(a,b) 
int lcm(int a, int b){
	return a*b/gcd(a,b);	//	Ϊ�˷�ֹint����������Ƚ��г������㣬�ڳˣ�
	//return a/gcd(a, b)*b;,	//	��Ϊa/gcdһ���������� 
} 
/*
Author:Apolo
Time : 2017-01-14
Problem Description������һ�������������Ľ��ƣ��жϸ����͸���ת�����Ƿ������� 
Method��
*/

#include<cstdio>
#include<cmath>
#define maxn 100010
bool isPrime(int N){
	if(N == 1){
		return false;
	}else{
		int sqr = (int)sqrt(1.0*N);
		for(int i = 2; i <= sqr; ++i){
			if(N % i == 0){
				return false;
			}
		}
	}
	return true;
}
int d[maxn];
int main(){
	int n,radix;
	while(scanf("%d", &n) != EOF){
		if(n < 0){break;}
		scanf("%d", &radix);
		if(isPrime(n) == false){
			printf("No\n");
		}else{
			//��NתΪradix���Ƶ����������鲢��ת
			int index = 0;
			do{
				d[index++] = n % radix;
				n /= radix;
			}while(n != 0);
			//�����������ת��ʾΪʮ����
			int ans = 0;
			for(int i = 0; i < index; ++i){
				ans = ans * radix + d[i];
			}
			if(isPrime(ans)){
				printf("Yes\n");
			}else{
				printf("No\n");
			}	
		}
	}
	return 0;
}
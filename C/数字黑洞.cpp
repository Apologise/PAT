/*
������һ����λ���ֲ���ȫ��ͬ��4λ����������������Ȱ�4�����ְ��ǵ��������ٰ��ǵݼ�����Ȼ���õ�1�����ּ���2�����֣����õ�

һ���µ����֡�һֱ�ظ������������Ǻܿ��ͣ���С����ֺڶ���֮�Ƶ�6174��������������Ҳ��Kaprekar������
���磬���Ǵ�6767��ʼ�����õ�

7766 - 6677 = 1089

9810 - 0189 = 9621

9621 - 1269 = 8352

8532 - 2358 = 6174

7641 - 1467 = 6174

... ...

�ָ�������4λ�����������д������ʾ����ڶ��Ĺ��̡�
��������:
�������һ��(0, 10000)�����ڵ�������N��


�������:
���N��4λ����ȫ��ȣ�����һ���������N - N = 0000�������򽫼����ÿһ����һ���������ֱ��6174��Ϊ����֣������ʽ������,ÿ���м�û�п��С�ע��ÿ�����ְ�4λ����

ʽ�����
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

//�Զ����������
bool cmpUpper(int x,int y){
	return x > y;
}

bool cmpLower(int x, int y){
	return x < y;
}

int convert(int x, int &A,int &B){
	int i = 0;
	int tmp = x;
	int resultA[4] = {0},resultB[4] = {0},result[4] = {0};
	while(x != 0){
		result[i++] = x % 10;
		x = x/10;
	}
	if( (result[0] == result[1]) && (result[0] == result[2]) &&
		(result[0] == result[3])){
		printf("%d - %d = 0000",tmp,tmp);
		return 0;
	}
		
	//����C++sort����

	sort(result,result+4,cmpUpper);
	A = result[0]*1000+result[1]*100+result[2]*10+result[3];
	sort(result,result+4,cmpLower);
	B = result[0]*1000+result[1]*100+result[2]*10+result[3];
	printf("%04d - %04d = %04d\n",A,B,A-B);
	
	return A - B;
}

int main(){
	int N;
	scanf("%d",&N);
	/*int  A[4],B[4],result[4],temp = 0;*/
	int A = 0, B = 0,temp = 0;
	temp = convert(N,A,B);
	if(temp != 0){
	while(temp != 6174){
		temp = convert(temp,A,B);
	}
	//convert(temp,A,B);
	}
	//Test:convert
	/*printf("%d %d",A,B);*/
	return 0;
}
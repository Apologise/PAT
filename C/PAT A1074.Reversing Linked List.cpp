/*
Author:Apolo
Time : 
Problem Description��
Method���������飬�ֱ��ŵ�ַ�����ݣ���һ����ַ��Ȼ����׵�ַ��ʼ����ַ����������У�Ȼ����ݿ������� 
*/
#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;

int address,data[maxn],next[maxn];
int f[maxn];

int main(){
	int firstAddress,N,K;
	scanf("%d%d%d",&firstAddress, &N, &K);
	while(N--){
		
	}
	int count = 0;
	for(int i = firstAddress; i != -1; i = next[i]){
		f[count++] = i;
	}
	printf("count��ֵΪ��%d\n",count); 

	for(int i = 0; i + K <= count; i += K){	//	i+kҪС���ܵĽڵ��� 
		int left = i, right = i + K - 1;
		while(left < right){
			swap(f[left], f[right]);
			left++;
			right--;
		}
			 
	}
	
	
	//�������
	for(int i = 0; i < count; ++i){
		if(i < count -1){
			printf("%05d %d %05d\n", f[i], data[f[i]], f[i + 1]);
		}else{
			printf("%05d %d -1\n");
		}
	} 
	return 0;
	
} 

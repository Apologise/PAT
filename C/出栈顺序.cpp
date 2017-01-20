/*
Author:Apolo
Time : 2017-01-19
Problem Description����1-N��ջ������ջͬʱ���Գ�ջ��Ȼ������K�����У��ж������Ƿ�Ϸ� 
Method������������б�����arr�����У�Ȼ���1��N��������i��ջ�����i�������еĵ�һ��������ô�����ջ��
Ȼ���������������֪��ջΪ�գ�����flag == true����ʾ�Ϸ� 
*/
#include<stack>
#include<cstdio>
using namespace std;

stack<int> st;
int arr[1010];

int main(){
	int M,N,K;
	scanf("%d%d%d",&M, &N,&K);
	while(K--){
		//����������д����arr�����У����ջ
		while(!st.empty()){st.pop();}
		for(int i = 1; i <= N; ++i){
			scanf("%d", &arr[i]);
		}
		//1-N����
		bool flag = true;
		int index = 1;
		for(int i = 1; i <= N; ++i){
			st.push(i);
			if(st.size() > M){
				flag = false;
				break;
			}
			while(!st.empty() && st.top() == arr[index]){
				st.pop();
				index++;
			}
		}
		//����ж�ջ�Ƿ�Ϊ�ղ���flag�Ƿ�Ϊtrue
		if(st.empty() && flag == true){
			printf("YES\n"); 
		} else{
			printf("NO\n");
		}
	} 
	return 0;
}
/*
Author:Apolo
Time : 2017-01-19
Problem Description：将1-N入栈，在入栈同时可以出栈，然后输入K个序列，判断序列是否合法 
Method；将输入的序列保存在arr数组中，然后从1到N遍历，将i入栈，如果i等于序列的第一个数，那么将其出栈，
然后继续上述操作，知道栈为空，并且flag == true，表示合法 
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
		//将输入的序列存放在arr数组中，清空栈
		while(!st.empty()){st.pop();}
		for(int i = 1; i <= N; ++i){
			scanf("%d", &arr[i]);
		}
		//1-N遍历
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
		//最后判断栈是否为空并且flag是否为true
		if(st.empty() && flag == true){
			printf("YES\n"); 
		} else{
			printf("NO\n");
		}
	} 
	return 0;
}
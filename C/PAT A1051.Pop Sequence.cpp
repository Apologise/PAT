#include<stack>
#include<cstdio>
#define maxn 10010
using namespace std;
stack<int> st;
int arr[maxn];
int main(){
	int M,N,K;
	scanf("%d%d%d",&M, &N, &K);
	for(int i = 0; i < K; ++i){
		//1.Çå¿ÕÕ»

		while(!st.empty()){st.pop();}
		for(int j = 1; j <= N; ++j){
			scanf("%d", &arr[j]);
		}
		int current = 1;
		bool flag = true;
		for(int k = 1; k <= N; ++k){
			st.push(k);
			if(st.size() > M){
				flag = false;
				break;
			}
			while(!st.empty() && st.top() == arr[current]){
				st.pop();
				current++;
			}
		}
		if(st.empty() == true && flag == true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0; 
}
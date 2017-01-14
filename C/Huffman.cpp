#include<cstdio>
#include<queue>
using namespace std;

//less<int>建立一个大顶堆，greater<int>建立一个小顶堆
priority_queue<int, vector<int>, greater<int>> Q;	//	建立一个小顶堆

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		while(Q.empty() == false){ Q.pop();}
		for(int i = 1; i <= n; ++i){
			int x;
			scanf("%d", &x);
			Q.push(x);
		}
		int ans = 0;
		while(Q.size() > 1){
			int a  = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans = a + b;
			Q.push(a + b);
		}
		printf("%d\n", ans);
	}
	return 0;
}
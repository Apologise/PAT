#include<cstdio>
#include<queue>
using namespace std;

//less<int>����һ���󶥶ѣ�greater<int>����һ��С����
priority_queue<int, vector<int>, greater<int>> Q;	//	����һ��С����

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
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int N,P;
	int num[100010];
	scanf("%d%d", &N, &P);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &num[i]);
	}
	sort(num+1, num+1+N);
	int i,j,count = 1;
	for(i = 1, j = 1;  i <= N && j <= N;){
		while(j <= N && num[j] <= (long long) num[i] * P){
			count = max(count, j-i+1);
			j++;
		}
		i++;
	}
	printf("%d\n", count);
	return 0;
}
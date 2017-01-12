#include<cstdio>
#define maxn 100000010

int N, M, sum[100010] = {0},nearM = 100000010;

int upper_bound(int A[], int left, int right,int x){
	while(left < right){
		int mid = (left + right) / 2;
		if(A[mid] > x){
			right = mid;
		}else {
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}

	for(int i = 1; i <= N; ++i){
		int j = upper_bound(sum, i, N + 1, sum[i - 1] + M);
		if( sum[j -1] - sum[i - 1] == M){
			nearM = M;
			break;
		}else if(sum[j] - sum[i - 1] < nearM && j <= N){
			nearM = sum[j] - sum[i - 1];
		}
	}

	for(int i = 1; i <= N; ++i){
		int j = upper_bound(sum,i, N+1,sum[i -1] + nearM);
		if(sum[j - 1] - sum[ i -1] == nearM){
			printf("%d-%d\n",i, j -1);
		}
	}
	return 0;
}
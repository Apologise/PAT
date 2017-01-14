#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;


int  num[100010];

int binarySearch(int N[], int left, int right, int x){
	
	while(left<= right){
		int mid = (left + right) / 2;
		if(N[mid] == x){
			return mid;
		}else if(N[mid] < x){
			left = mid + 1;
		}else {
			right = mid -1;
		}
	}
	return -1;
}

int main(){
	int n, M;
	scanf("%d%d", &n,&M);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
	}

	sort(num,num +n);
	int i;
	for( i = 0; i < n; ++i){
		int ans = binarySearch(num, i,n-1, M - num[i]);
		if(i != ans && ans != -1){
			printf("%d %d",M- num[ans],num[ans]);
			break;
		}
	}
	if(i == n){
		printf("No Solution\n");
	}
	return 0;
}
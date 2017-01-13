#include<cstdio>
#include<algorithm>
using namespace std;


//反思：二分法中while（left <= right）,千万别因为粗心写成left < right
int binarySearch(int A[],int left, int right, int x){
	while(left <= right){
		int mid = (left + right) / 2;
		if(A[mid] == x){
			return mid;
		}else if(A[mid] > x){
			right = mid -1;
		}else{
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
	int N, M,res;
	int coins[100010];
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; ++i){
		scanf("%d",&coins[i]);
	}
	sort(coins+1, coins + N +1);
	int i;
	for( i = 1; i <= N; ++i){
		res = binarySearch(coins,i,N,M - coins[i]);
		if(res != -1 && res != i){
			printf("%d %d\n",M-coins[res],coins[res]);
			break;
		}
	}
	if(i == N +1){
		printf("No Solution\n");
	}
	return 0;

}
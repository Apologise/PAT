#include<cstdio>
#include<algorithm>
#define LL long long
#define maxn 100010
using namespace std;

int n,p;	//数列的长度
int a[maxn] = {0};

int binarySearch(int i, LL x){
	if(a[n-1] <= x){return n;}
	int left = i + 1, right = n-1;
	while(left < right){
		int mid = (left + right) /2;
		if(a[mid] <= x){
			left = mid + 1;
		}else {
			right = mid;
		}
	}
	return left;
}

int main(){
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 1;
	for(int i = 0; i < n; ++i){
		int j = binarySearch(i,(LL)a[i]*p);
		ans = max(ans,j - i);
	}
	printf("%d",ans);
	return 0;
}VA3ZZ24ECJKGAGGW
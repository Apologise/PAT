#include<cstdio>

int cal(int n, int p){
	int ans = 0;
	while(n){
		ans += n / p;
		n /= p;
	}
	return ans;  
}

int main(){
	printf("%d",cal(10, 5));
	return 0;
}
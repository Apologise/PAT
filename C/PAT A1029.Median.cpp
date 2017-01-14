#include<cstdio>
#include<algorithm>
#define maxn 1000010
using namespace std;

//反思：在标记1出要细心，是j<m !!细心细心细心！！！
long long num1[maxn],num2[maxn],temp[maxn];
int count = 0, n,m;

int main(){
	int count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%lld", &num1[i]);
	}
	scanf("%d",&m);
	for(int i = 0; i < m; ++i){
		scanf("%lld", &num2[i]);
	}
	
	int i = 0, j = 0;
	while(i < n && j < m && count <= (m + n -1) / 2  ){
		if(num1[i] < num2[j]){
			temp[count++] = num1[i++];
		}else{
			temp[count++] = num2[j++];
		}
	}
	
	while(i < n && count <= (m + n -1) / 2){
		temp[count++] = num1[i++];
	}
	
	while(j < m && count <= (m + n -1) /2){
		temp[count++] = num2[j++];
	}
	if(count == (m + n -1) / 2 + 1){
		printf("%lld\n",temp[count-1]);
	}
	return 0;
}


//#include<cstdio>  
//#include<string>  
//#include<cstring>  
//#include<vector>  
//#include<iostream>  
//#include<queue>  
//#include<map>  
//#include<bitset>  
//#include<algorithm>  
//using namespace std;  
//typedef long long LL;  
//const int INF = 0x7FFFFFFF;  
//const int mod = 1e9 + 7;  
//const int maxn = 1e6 + 10;  
//int n, m;  
//LL a[maxn], b[maxn], x;  
//  
//int main()  
//{  
//    scanf("%d", &n); for (int i = 0; i < n; i++) scanf("%lld", &a[i]);  
//    scanf("%d", &m); for (int i = 0; i < m; i++) scanf("%lld", &b[i]);  
//    for (int i = 0, j = 0, k = 1;; k++)  
//    {  
//        if (i < n && (a[i] <= b[j] || j == m)) x = a[i++]; else x = b[j++];  
//        if (k == (n + m + 1) / 2) { printf("%lld\n", x); break; }  
//    }  
//    return 0;  
//} 
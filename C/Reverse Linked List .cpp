#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;

struct Node{
	int address, data, nt;
	int order;
	bool flag;
	Node(){
		flag = false;
		order = maxn;
	}
}node[maxn];

int f[maxn];
int main(){
	int begin, n, K, address;
	scanf("%d%d%d", &begin, &n, &K);
	for(int i = 0; i < n; ++i){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].nt);
		node[address].address = address;
	}
	
	int p = begin, count = 0;
	for(; p != -1; p = node[p].nt){
		f[count++] = p;	
	}
	
	for(int i = 0; i + K <= count; i += K){
		int left = i, right = i + K - 1;
		while(left < right){
			swap(f[left++], f[right--]);
		}
	}
	  for (int i = 0; i < count; i++)  
    {  
        if (i < count - 1) printf("%05d %d %05d\n", f[i], node[f[i]].data, f[i + 1]);  
        else printf("%05d %d -1\n", f[i], node[f[i]].data);  
    }  
    return 0;
}



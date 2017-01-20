#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
struct node{
	int data;
	int address;
	int next;
	bool flag;
	node(){
		flag = false;
	}
};

node nd[maxn];

bool cmp(node a, node b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;
	}else{
		return a.data < b.data;
	}
}

int main(){
	int N, firstAddress;
	scanf("%d%d", &N, &firstAddress);
	for(int i = 1; i <= N; ++i){
		int address, data, next;
		scanf("%d%d%d",&address,&data, &next);
		nd[address].data = data;
		nd[address].next = next; 
		nd[address].address = address;
	}
	
	//遍历整个链表将出现在firstAddress链上的节点标记为true
	int p,count = 0;
	for(p = firstAddress; p != -1; p = nd[p].next) {
		nd[p].flag = true;
		count ++;
	}
	if(count == 0){
		printf("0 -1");
	}else{
		sort(nd, nd + maxn, cmp);
		printf("%d %05d\n", count, nd[0].address);
		for(int i = 0; i < count; ++i){
			if(i != count -1){
			printf("%05d %d %05d\n", nd[i].address, nd[i].data,nd[i+1].address);
			}else{
				printf("%05d %d -1\n", nd[i].address, nd[i].data);
			}
		}
	}
	return 0;
}
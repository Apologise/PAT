#include<cstdio>
#include<queue>
#define maxn 1010
using namespace std;
struct mouse{
	int weight;
	int R;
} mouse[maxn];

int main(){
	int np,ng,order;
	scanf("%d%d",&np,&ng);
	for(int i = 0; i < np; ++i){
		scanf("%d",&mouse[i].weight);
	}
	queue<int> q;
	for(int i = 0; i < np; ++i){
		scanf("%d",&order);
		q.push(order);
	}
	int temp = np, group;
	while(q.size() != 1){
		if(temp % ng == 0){
			group = temp / ng;
		}else{
			group = temp / ng + 1;
		}
		for(int i = 0; i < group; ++i){
			int k = q.front();	//frontΪȡ��ͷԪ��
			for(int j = 0; j < ng; ++j){
				if(i*ng + j >= temp){
					break;
				}
				int front = q.front();
				if(mouse[front].weight > mouse[k].weight){
					k = front;
				}
				mouse[front].R  = group + 1;
				q.pop();
			} 
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].R = 1;
	for(int i = 0; i < np; i++){
		printf("%d",mouse[i].R);
		if(i < np - 1){
			printf(" ");
		}
	}
	return 0;
}
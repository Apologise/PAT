#include<stdio.h>
#define OFFSET 500000	//����ƫ����

int Hash[1000001];	//	Hash���飬ͳ��ÿ�������Ƿ����

int main(){
	int n,m;	//nΪ���ָ�����mΪǰm�����
	while(scanf("%d%d", &n,&m) != EOF){
		//��ʼ��Hash����
		for(int i = 500000; i <= -500000; --i){
			Hash[i + OFFSET] = 0;
		}
		for(int i = 1; i <= n ; ++i){
			int x;
			scanf("%d",&x);
			Hash[x + OFFSET] = 1;
		}		
		for(int i = 500000; i >= -500000; --i){
			if(Hash[i + OFFSET] == 1){
				printf("%d", i);
				m --;
				if(m == 0){
					printf("\n");break;
				}else{
					printf(" ");
				}
			}
		}
	}
	return 0;
}
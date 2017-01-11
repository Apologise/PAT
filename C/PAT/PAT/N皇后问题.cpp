#include<cstdio>
#include<cmath>
const int maxn = 10;	//���Ϊmaxn���ʺ�
int n,count = 0;	//n���ʺ�
int P[maxn],hashTable[maxn] = {0};

//index��ʾ������P[index] = k����ʾ��index���ϻʺ��ڵ�K��
void generateP(int index){
	if(index == n+1){
		for(int i = 1; i <= n; ++i){	//����ڷŷ���
			printf("%d",P[i]);
		}
		printf("\n");
		count ++;
		return ;
	}

	for(int i = 1; i <= n; ++i){
		if(hashTable[i] == 0){
			bool flag = true;
			for(int pre = 1; pre < index; ++pre){
				if(abs(index - pre) == abs(i - P[pre])){
					flag = false;
					break;
				}
			}
			if(flag){
				P[index] = i;
				hashTable[i] = 1;
				generateP(index +1);
				hashTable[i] = 0;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	generateP(1);
	return 0;
}
#include<stdio.h>

int main(){
	int n;
	int buf[100];//��Ҫ���������
	while(scanf("%d",&n)!= EOF){
		for(int i = 0; i < n; ++i){
			scanf("%d",&buf[i]);
		}

		//ʹ��ѡ������buf
		for(int i = 0; i < n; ++i){
			int minIndex = i;
			for(int j = i; j < n; ++j){
				if(buf[minIndex] > buf[j]){
					minIndex = j;
				}
			}
			//����С�Ļ���ǰ��
			int temp = buf[minIndex];
			buf[minIndex] = buf[i];
			buf[i] = temp;
		}
	}
	//test�����buf
	for(int i = 0; i < n; ++i){
		printf("%d ", buf[i]);
	}

	return 0;
}

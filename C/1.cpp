#include<stdio.h>

int main(){
	int n;
	int buf[100];//将要排序的数字
	while(scanf("%d",&n)!= EOF){
		for(int i = 0; i < n; ++i){
			scanf("%d",&buf[i]);
		}

		//使用选择排序buf
		for(int i = 0; i < n; ++i){
			int minIndex = i;
			for(int j = i; j < n; ++j){
				if(buf[minIndex] > buf[j]){
					minIndex = j;
				}
			}
			//将最小的换到前面
			int temp = buf[minIndex];
			buf[minIndex] = buf[i];
			buf[i] = temp;
		}
	}
	//test：输出buf
	for(int i = 0; i < n; ++i){
		printf("%d ", buf[i]);
	}

	return 0;
}

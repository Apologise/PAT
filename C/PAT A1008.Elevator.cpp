/*
Author:Apolo
Time : 2017-01-14
Problem Description�����㻨�ѵ���ʱ�� 
Method����¼��һ���¥�� 
*/

#include<cstdio> 

int main(){
	int N;
	scanf("%d", &N);
	int ans = 0,preFloor = 0, floor;
	for(int i = 1; i <= N; ++i){
		scanf("%d",&floor);
		int dis = floor - preFloor;
		preFloor = floor;
		
			if(dis > 0){
				ans += dis*6+5;
			}else{
				ans += (-dis)*4+5;
			}
		
	}
	printf("%d\n",ans);
	return 0;
}
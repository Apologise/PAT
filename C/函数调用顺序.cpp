#include<stdio.h>

void room1();
void room2();

int main(){
	printf("I am in main and call room1\n");
	room1();
	return 0;
} 

void room2(){
	printf("room2\n");
}
void room1(){
	printf("room1, I am calling room2\n");
	room2();
}

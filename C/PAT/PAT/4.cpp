#include<stdio.h>
#include<string.h>
int main(){
 char a[1000];
 int c,b,d,i,e[1000],t;
 scanf("%s\t%d",a,&b);
 t=strlen(a);
 for(i=0;i<t;i++){
  
   c=((a[i]-'0')*10+(a[i+1]-'0'))/b;
   d=((a[i]-'0')*10+(a[i+1]-'0'))%b;
   e[i]=c;
   a[i+1]=d+'0';
   if(i==t-2)
   break;
 }
 for(i=0;i<t-1;i++)
 printf("%d",e[i]);
 printf(" ");
 printf("%d\n",d);
 return 0; 
}
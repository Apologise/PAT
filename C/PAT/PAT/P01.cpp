
#include <stdio.h>
#include <stdlib.h>
 
int comp(long int a,long int b,long int c)
{
    int r =(a+b)>c?(1):(0);
    return r;
}
 
int main()
{
    int num = 0,i=0;
    long int a,b,c;
    scanf("%d",&num);
    int result[num];
    for(i=0;i<num;i++){
        scanf("%ld%ld%ld",&a,&b,&c);
        result[i] = comp(a,b,c);
    }
    for(i=0;i<num;i++){
        if(result[i]==1)
            printf("Case #%d: true\n",i+1);
        else
            printf("Case #%d: false\n",i+1);
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter a 2 number: ");
    scanf("%d%d",&a,&b);
    //using conditional operator
    int max = (a>b)? a:b;
    printf("largest number = %d\n",max);
    return 0;
}
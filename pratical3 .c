#include<stdio.h>
#define RATE 5
int main()
{
    const float PI=3.14;
    float area,radius;
    int amount,intrest;
    printf("Enter radius : ");
    scanf("%f",&radius);
    area=PI*radius*radius;
    printf("area of circle = %2f\n",area);
    printf("%d",amount);
    intrest=(amount*RATE)/100;
    printf("intrest = %d\n",intrest);
    return 0;
}

#include<stdio.h>
int main()
{
    int a=52;
    float f;
    //implicate conversion
    f=a;
    printf("Implicit Conversion:\n");
    printf("Integer a=%d\n",a);
    printf("convert to float f=%2f\n",f);
    //explicite conversion
    float b=1.00;
    int x;
    x=(int)b;
    printf("\nExplicit Conversion\n");
    printf("original float no: b=%2f\n",b);
    printf("After type casting to int x=%d\n",x);
    return 0;

}

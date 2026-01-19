#include<stdio.h>

int main()
{
    int a,b,choise;

    printf("Enter a two number");
    scanf("%d%d",&a,&b);

    printf("1.Addition\n");
    printf("2.subtraction\n");
    printf("3.Multiplaction\n");
    printf("4.Division\n");
    printf("5.Module\n");

    printf("Enter your choice");
    scanf("%d",&choise);

    switch(choise)
    {
        case 1 : printf("Addition=%d\n",a+b); break;
        case 2 : printf("Subtraction=%d\n",a-b); break;
        case 3 : printf("Multiplication=%d\n",a*b); break;
        case 4 : printf("Division=%d\n",a/b); break;
        case 5 : printf("Module=%d\n",a%b); break;
    }

    return 0;
}

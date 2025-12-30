#include<stdio.h>
int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    // using nested condition operator
    (a > 0) ? printf("Positive\n"):
    (a < 0) ? printf("Negative\n"):
    printf("Zero\n");
    return 0;
}
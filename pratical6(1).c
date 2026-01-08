#include <stdio.h>

int main()
{
    int a, b;

    printf("Enter a two no.: ");
    scanf("%d %d", &a, &b);

    // Using condition operator
    int max = (a > b) ? a : b;

    printf("Largest number = %d\n", max);

    return 0;
}
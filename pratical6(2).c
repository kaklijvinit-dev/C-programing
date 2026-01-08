#include <stdio.h>

int main()
{
    int x;

    printf("Enter a no.: ");
    scanf("%d", &x);

    // Using nested condition operator
    (x > 0) ? printf("Positive\n") :
    (x < 0) ? printf("Negative\n") :
              printf("Zero\n");

    return 0;
}
#include <stdio.h>

int main()
{
    int n;
    char ch;

    /* Logical AND (&&) */
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n >= 1 && n <= 100)
        printf("Number is inside range\n");
    else
        printf("Number is outside range\n");

    /* Logical OR (||) */
    printf("\nEnter a character: ");
    scanf(" %c", &ch);   // space before %c is important

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        printf("It is Vowel\n");
    else
        printf("It is Consonant\n");

    /* Logical NOT (!) */
    if (!(n % 2))
        printf("\nThe number %d is Even\n", n);
    else
        printf("The number %d is Odd\n", n);

    return 0;
}
#include <stdio.h>
#define PI 3.14

int main()
{
    const float RATE = 5.0;
    int a, b;
    float radius, principal, time;
    float sum, diff, prod, quot;
    float area, SI;
    printf("Enter a 2 no: ");
    scanf("%d%d", &a, &b);
    sum = a + b;
    diff = a - b;
    prod = a * b;
    quot = a / b;
    printf("Circle: ");
    scanf("%f", &radius);
    area = PI*radius*radius;
    printf("Enter principal and time: ");
    scanf("%f%f", &principal, &time);
    SI = (principal*time*RATE) / 100;
    return 0;
}

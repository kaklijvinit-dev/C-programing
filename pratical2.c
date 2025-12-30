#include <stdio.h>
int main()
{
    char fname[20],mname[20],lname[20];
    int roll , dd,mm,yy;
    float per;
    printf("Enter full name: ");
    scanf("%s%S%S",fname,mname,lname);
    printf("Enter roll no: ");
    scanf("%d",&roll);
    printf("Enter perctange: ");
    scanf("%f",&per);
    printf("Enter DOB: ");
    scanf("%d%d%d");
    printf("\n name: %s%s%s fname,manme,lname");
    printf("\n roll no: %d",&roll);
    printf("\n Dob: %02d/%02d/%04d/dd,mm,yy");

    return 0;

}

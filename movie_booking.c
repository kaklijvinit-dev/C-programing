#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ROW 5
#define COL 5

int seats[ROW][COL] = {0};

/* ------------ MOVIE DATA ------------ */

char movies[10][50] = {
    "Dhurandhar",
    "Pushpa 2: The Rule",
    "Kalki 2898 AD",
    "Singham Again",
    "Stree 2",
    "Fighter",
    "Crew",
    "Devara: Part 1",
    "Bade Miyan Chote Miyan",
    "Border 2"
};

float price[10] = {
    150.63,80.63,90.36,12.6,130.52,
    80.45,112.3,50.6,70.52,299.99
};

/* ------------ VALIDATION ------------ */

int validEmail(char email[])
{
    return strstr(email,"@gmail.com")!=NULL;
}

int validMobile(char mobile[])
{
    if(strlen(mobile)!=10) return 0;
    for(int i=0;i<10;i++)
        if(mobile[i]<'0'||mobile[i]>'9')
            return 0;
    return 1;
}

/* ------------ ENCRYPT FUNCTIONS ------------ */

void encryptEmail(char email[])
{
    for(int i=2; email[i]!='@' && email[i]!='\0'; i++)
        email[i]='*';
}

void encryptMobile(char mobile[])
{
    int len=strlen(mobile);
    for(int i=2;i<len-2;i++)
        mobile[i]='*';
}

/* ------------ SAVE DATA TO EXCEL ------------ */

void saveToExcel(char movie[],int r,int c,
                 float total,char email[],char mobile[])
{
    FILE *fp=fopen("booking_history.csv","a");
    fprintf(fp,"%s,%c%d,%.2f,%s,%s\n",
            movie,'A'+r,c+1,total,email,mobile);
    fclose(fp);
}

/* ------------ ADMIN LOGIN ------------ */

void adminLogin()
{
    char id[20],pass[20];

    while(1)
    {
        printf("\n===== ADMIN LOGIN =====\n");

        printf("Enter ID: ");
        scanf("%s",id);

        printf("Enter Password: ");
        scanf("%s",pass);

        if(strcmp(id,"vinit")==0 &&
           strcmp(pass,"210609")==0)
        {
            printf("Login Successful!\n");
            break;
        }
        else
            printf("Invalid Login! Try Again.\n");
    }
}

/* ------------ MAIN PROGRAM ------------ */

int main()
{
    adminLogin();

    while(1)   /* continuous booking */
    {
        int choice,r,c;
        float total,extra=0;
        char email[50],mobile[20],seatInput[5];
        char quitOption;

        printf("\n===== MOVIE LIST =====\n");

        for(int i=0;i<10;i++)
            printf("%d. %s - %.2f\n",
                   i+1,movies[i],price[i]);

        printf("Select Movie (1-10): ");
        scanf("%d",&choice);

        if(choice<1 || choice>10)
        {
            printf("Invalid choice!\n");
            continue;
        }

        /* ----- SEAT LAYOUT ----- */
        printf("\nSeat Layout (XX = Booked)\n");
        printf("   1  2  3  4  5\n");
        for(int i=0;i<ROW;i++)
        {
            printf("%c ", 'A'+i);
            for(int j=0;j<COL;j++)
            {
                if(seats[i][j]==1)
                    printf("XX ");
                else
                    printf("__ ");
            }
            printf("\n");
        }

        /* ----- SEAT INPUT ----- */
        while(1)
        {
            printf("Enter Seat (e.g., B3) or Q to Quit: ");
            scanf("%s",seatInput);

            if(toupper(seatInput[0])=='Q')
            {
                printf("Exiting Booking. Thank you!\n");
                return 0; // quit program
            }

            if(strlen(seatInput)<2 || strlen(seatInput)>3)
            {
                printf("Invalid format! Use RowLetterColumnNumber (e.g., B3)\n");
                continue;
            }

            r = toupper(seatInput[0]) - 'A';
            c = atoi(&seatInput[1]) - 1;

            if(r<0 || r>=ROW || c<0 || c>=COL)
            {
                printf("Seat out of range! A-E, 1-5\n");
                continue;
            }

            if(seats[r][c]==1)
            {
                printf("Seat Already Booked!\n");
                continue;
            }

            break;
        }

        /* ----- EXTRA CHARGES ----- */
        extra=0;
        if((r==0||r==4)&&(c==0||c==4))
        {
            extra+=40;
            printf("Corner Seat Extra +40\n");
        }

        if(r==2&&(c==1||c==2||c==3))
        {
            extra+=60;
            printf("Couple Seat Extra +60\n");
        }

        total=price[choice-1]+extra;

        /* ----- EMAIL INPUT ----- */
        while(1)
        {
            printf("Enter Email: ");
            scanf("%s",email);

            if(validEmail(email))
                break;
            else
                printf("Invalid Email! Use @gmail.com\n");
        }

        /* ----- MOBILE INPUT ----- */
        while(1)
        {
            printf("Enter Mobile (10 digits): ");
            scanf("%s",mobile);

            if(validMobile(mobile))
                break;
            else
                printf("Invalid Mobile Number!\n");
        }

        encryptEmail(email);
        encryptMobile(mobile);

        seats[r][c]=1;

        printf("\n===== BOOKING SUCCESS =====\n");
        printf("Movie : %s\n",movies[choice-1]);
        printf("Seat  : %c%d\n",'A'+r,c+1);
        printf("Total : %.2f\n",total);
        printf("Encrypted Email : %s\n",email);
        printf("Encrypted Mobile: %s\n",mobile);

        saveToExcel(movies[choice-1],r,c,total,email,mobile);

        printf("\nBooking stored in Excel file!\n");
	printf("\nDevloped by Vinit M. Kaklij\n");
    }

    return 0;
}

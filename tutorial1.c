#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    150.63, 80.63, 90.36, 12.6, 130.52,
    80.45, 112.3, 50.6, 70.52, 299.99
};

/* ------------ ENCRYPT FUNCTIONS ------------ */

void encryptEmail(char email[])
{
    int i;
    for(i = 2; email[i] != '@' && email[i] != '\0'; i++)
        email[i] = '*';
}

void encryptMobile(char mobile[])
{
    int len = strlen(mobile);

    for(int i = 2; i < len-2; i++)
        mobile[i] = '*';
}

/* ------------ DISPLAY SEATS ------------ */

void showSeats()
{
    printf("\nSeat Layout (0=Available,1=Booked)\n");

    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
            printf("%d ", seats[i][j]);
        printf("\n");
    }
}

/* ------------ SAVE DATA TO EXCEL ------------ */

void saveToExcel(char movie[], int r, int c,
                 float total, char email[], char mobile[])
{
    FILE *fp;

    fp = fopen("booking_history.csv","a");

    fprintf(fp,"%s,%d-%d,%.2f,%s,%s\n",
            movie,r,c,total,email,mobile);

    fclose(fp);
}

/* ------------ ADMIN LOGIN ------------ */

void adminLogin()
{
    char id[20], pass[20];

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
        {
            printf("Invalid Login! Try Again.\n");
        }
    }
}

/* ------------ MAIN PROGRAM ------------ */

int main()
{
    adminLogin();

    while(1)   // continuous booking
    {
        int choice,r,c;
        float total, extra = 0;
        char email[50], mobile[20];

        printf("\n===== MOVIE LIST =====\n");

        for(int i=0;i<10;i++)
            printf("%d. %s - %.2f\n",
                   i+1,movies[i],price[i]);

        printf("Select Movie: ");
        scanf("%d",&choice);

        if(choice<1 || choice>10)
        {
            printf("Invalid choice!\n");
            continue;
        }

        showSeats();

        printf("Enter Row (0-4): ");
        scanf("%d",&r);

        printf("Enter Column (0-4): ");
        scanf("%d",&c);

        if(seats[r][c]==1)
        {
            printf("Seat Already Booked!\n");
            continue;
        }

        extra = 0;

        /* Corner seat charge */
        if((r==0 || r==4) && (c==0 || c==4))
        {
            extra += 40;
            printf("Corner Seat Extra +40\n");
        }

        /* Couple seat charge */
        if(r==2 && (c==1 || c==2 || c==3))
        {
            extra += 60;
            printf("Couple Seat Extra +60\n");
        }

        total = price[choice-1] + extra;

        printf("Enter Email: ");
        scanf("%s",email);

        printf("Enter Mobile: ");
        scanf("%s",mobile);

        encryptEmail(email);
        encryptMobile(mobile);

        seats[r][c] = 1;

        printf("\n===== BOOKING SUCCESS =====\n");
        printf("Movie : %s\n",movies[choice-1]);
        printf("Seat  : (%d,%d)\n",r,c);
        printf("Total : %.2f\n",total);
        printf("Encrypted Email : %s\n",email);
        printf("Encrypted Mobile: %s\n",mobile);

        saveToExcel(movies[choice-1],r,c,
                    total,email,mobile);

        printf("\nBooking stored in Excel file!\n");
    }

    return 0;
}
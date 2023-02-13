
// Airline Seat Reservation System

#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Passenger
{
    int collumnNumber;
    int rowNum;
    int reserved;

    int age;
    char FullN[30];
    char city[30];
}pass;

int PassengerNum = 0;
pass passengers[100];

char seats[10][6];
void defSeats()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<6; j++)
        {
            seats[i][j] = ' ';
        }
    }
}

void passengerList();
void reservation(int n);
void selectSeat(int n);
void changeSeat(int n);
void removeSeat(int n);

void saveFile();


void resMenu()
{
    system("cls");

    if(PassengerNum == 0)
    {
        printf("\n\t\t\tNo passenger registered.\n");
        printf("\n");
        system("pause");
        system("cls");
        return;
    }

    int found = 0;
    int age;
    char FullN[30], city[30];

    printf("\n\t\t\t----------------------------------------\n");
    printf("\t\t\t|              Reservation               |\n");
    printf("\t\t\t------------------------------------------\n");
    printf("\n\t\t\tEnter passenger full name: ");
    gets(FullN);
    printf("\t\t\tEnter passenger age: ");
    scanf("%d", &age);
    fflush(stdin);
    printf("\t\t\tEnter passenger's city: ");
    gets(city);

    for(int i=0; i<PassengerNum; i++)
    {
        if(strcmp(FullN, passengers[i].FullN) == 0 && age == passengers[i].age && strcmp(city, passengers[i].city) == 0)
        {
            found = 1;
            reservation(i);
        }
    }

    if(found == 0)
    {
        printf("\n\t\t\tNo passenger found.\n");
        printf("\n");
        system("pause");
        system("cls");
    }
}



void regMenu()
{
    system("cls");

    int age;
    char FullN[30], city[30];

    printf("\n\t\t\t----------------------------------------\n");
    printf("\t\t\t|              Registration              |\n");
    printf("\t\t\t------------------------------------------\n");
    printf("\n\t\t\tPassenger full name: ");
    gets(FullN);
    printf("\t\t\tPassenger age: ");
    scanf("%d", &age);
    fflush(stdin);
    printf("\t\t\tPassenger's city: ");
    gets(city);

    for(int i=0; i<PassengerNum; i++)
    {
        if(strcmp(FullN, passengers[i].FullN) == 0 && age == passengers[i].age)
        {
            printf("\n\t\t\tPassenger is already registered.\n");
            return;
        }
    }

    printf("\n\t\t\tPassenger registered successfully.\n");
    strcpy(passengers[PassengerNum].FullN, FullN);
    strcpy(passengers[PassengerNum].city, city);
    passengers[PassengerNum].age = age;
    PassengerNum += 1;
}

int main()
{
    defSeats();

    char option;

    do
    {
        system("cls");

        printf("\n\t\t\t----------------------------------------\n");
        printf("\t\t\t|        Airline Seat Reservation        |\n");
        printf("\t\t\t------------------------------------------\n");
        printf("\t\t\t|                                        |\n");
        printf("\t\t\t|     1. Reservation                     |\n");
        printf("\t\t\t|     2. Registration                    |\n");
        printf("\t\t\t|     3. List of passengers              |\n");
        printf("\t\t\t|     4. Exit/Save                       |\n");
        printf("\t\t\t|                                        |\n");
        printf("\t\t\t-------------------------------------------\n");
        printf("\n\t\t\tSelect an Option: ");
        scanf(" %c", &option);
        fflush(stdin);

        switch(option)
        {
        case '1':
            resMenu();
            break;
        case '2':
            regMenu();
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '3':
            passengerList();
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '4':
            saveFile();
            break;
        default:
            printf("\n\t\t\tInvalid Option!\n");
            printf("\n");
            system("pause");
            system("cls");
        }
    }
    while(option != '4');

    return 0;
}

// FUNCTIONS

void passengerList()
{
    system("cls");

    printf("\n\t\t\t==========================================\n");
    printf("\t\t\t|            List of Passengers          |\n");
    printf("\t\t\t==========================================\n");

    if(PassengerNum == 0)
    {
        printf("\n\t\t\tNo passengers registered yet.\n");
        return;
    }

    char colLett;

    for(int i=0; i<PassengerNum; i++)
    {
        switch(passengers[i].collumnNumber)
        {
        case 1:
            colLett = 'A';
            break;
        case 2:
            colLett = 'B';
            break;
        case 3:
            colLett = 'C';
            break;
        case 4:
            colLett = 'D';
            break;
        case 5:
            colLett = 'E';
            break;
        case 6:
            colLett = 'F';
            break;
        }
        printf("\n\t\t\t[Passenger %d]\n", i+1);
        printf("\t\t\tFull name: %s\n", passengers[i].FullN);
        printf("\t\t\tAge: %d\n", passengers[i].age);
        printf("\t\t\tCity: %s\n", passengers[i].city);
        if(passengers[i].reserved == 1)
        {
            printf("\t\t\tReserved seat: %d%c\n", passengers[i].rowNum, colLett);
        }
    }
}

void reservation(int n)
{
    system("cls");

    char choice;

    do
    {
        printf("\n\t\t\tWelcome %s.\n", passengers[n].FullN);
        printf("\n\t\t\t\t==========================================\n");
        printf("\t\t\t\t|                  Seats                 |\n");
        printf("\t\t\t\t==========================================\n");
        printf("\n\t\t\t=========================================================");
        printf("\n\t\t\t|\t    A\t    B\t    C\t    D\t    E\t    F   |\n");
        printf("\t\t\t=========================================================\n");
        for(int i=0; i<10; i++)
        {
            printf("\t\t\t%d\t|", i+1);
            for(int j=0; j<6; j++)
            {
                printf("   %c\t|", seats[i][j]);
            }
            printf("\n");
        }
        printf("\t\t\t=========================================================\n");

        printf("\n\t\t\tOptions:\n");
        printf("\n\t\t\t1. Select a seat.\n");
        printf("\t\t\t2. Change seat number.\n");
        printf("\t\t\t3. Remove reservation.\n");
        printf("\t\t\t4. Return\n");
        printf("\n\t\t\tChoice: ");
        scanf(" %c", &choice);
        fflush(stdin);

        switch(choice)
        {
        case '1':
            selectSeat(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '2':
            changeSeat(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '3':
            removeSeat(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '4':
            break;
        default:
            printf("\n\t\t\tInvalid Choice!\n");
            system("pause");
            system("cls");
        }
    } while(choice != '4');
}

void selectSeat(int n)
{
    if(passengers[n].reserved == 1)
    {
        printf("\n\t\t\tYou already reserved a seat.\n");
        return;
    }

    int collumnNumber;
    int rowNum;
    char ch = ' ';
    char another;

    printf("\n\t\t\t[Seat number is a combination of number and letter ex. (6B, 3A).]\n");
    do
    {
        printf("\n\t\t\tEnter seat number: ");
        scanf("%d%c", &rowNum, &ch);
        fflush(stdin);

        switch(ch)
        {
        case 'A':
            collumnNumber = 1;
            break;
        case 'B':
            collumnNumber = 2;
            break;
        case 'C':
            collumnNumber = 3;
            break;
        case 'D':
            collumnNumber = 4;
            break;
        case 'E':
            collumnNumber = 5;
            break;
        case 'F':
            collumnNumber = 6;
            break;
        }

        if((rowNum > 10 || rowNum < 1) || (ch >= 'a' && ch <= 'z') || (ch <= '1' && ch <= '1000000') || (ch == ' ') || (ch > 'F'))
        {
            printf("\n\t\t\tInvalid seat number.\n");
            return;
        }

        if(seats[rowNum-1][collumnNumber-1] == 'X')
        {
            printf("\n\t\t\tThis seat is already taken. Select another seat? [Y/N]: ");
            scanf(" %c", &another);
            fflush(stdin);
            if(another != 'Y' && another != 'y')
            {
                return;
            }
        }
        else
        {
            another = 'N';
        }
    } while(another == 'Y' || another == 'y');

    seats[rowNum-1][collumnNumber-1] = 'X';
    passengers[n].reserved = 1;
    passengers[n].rowNum = rowNum;
    passengers[n].collumnNumber = collumnNumber;
    printf("\n\t\t\tSeat reserved.\n");
}

void changeSeat(int n)
{
    if(passengers[n].reserved == 0)
    {
        printf("\n\t\t\tYou have not yet reserved a seat.\n");
        return;
    }

    int collumnNumber;
    int rowNum;
    char ch = ' ';
    char colLett;
    char another;

    switch(passengers[n].collumnNumber)
    {
    case 1:
        colLett = 'A';
        break;
    case 2:
        colLett = 'B';
        break;
    case 3:
        colLett = 'C';
        break;
    case 4:
        colLett = 'D';
        break;
    case 5:
        colLett = 'E';
        break;
    case 6:
        colLett = 'F';
        break;
    }

    printf("\n\t\t\t[Changing seat number]\n");
    printf("\t\t\tYour current seat number: %d%c\n", passengers[n].rowNum, colLett);
    do
    {
        printf("\n\t\t\tEnter new seat number: ");
        scanf("%d%c", &rowNum, &ch);
        fflush(stdin);

        switch(ch)
        {
        case 'A':
            collumnNumber = 1;
            break;
        case 'B':
            collumnNumber = 2;
            break;
        case 'C':
            collumnNumber = 3;
            break;
        case 'D':
            collumnNumber = 4;
            break;
        case 'E':
            collumnNumber = 5;
            break;
        case 'F':
            collumnNumber = 6;
            break;
        }

        if((rowNum > 10 || rowNum < 1) || (ch >= 'a' && ch <= 'z') || (ch <= '1' && ch <= '1000000') || (ch == ' '))
        {
            printf("\n\t\t\tInvalid seat number.\n");
            return;
        }

        if(seats[rowNum-1][collumnNumber-1] == 'X')
        {
            printf("\n\t\t\tThis seat is already taken. Select another seat? [Y/N]: ");
            scanf(" %c", &another);
            fflush(stdin);
            if(another != 'Y' && another != 'y')
            {
                return;
            }
        }
        else
        {
            another = 'N';
        }
    } while(another == 'Y' || another == 'y');

    seats[passengers[n].rowNum-1][passengers[n].collumnNumber-1] = ' ';
    seats[rowNum-1][collumnNumber-1] = 'X';
    passengers[n].rowNum = rowNum;
    passengers[n].collumnNumber = collumnNumber;
    printf("\n\t\t\tSeat number changed.\n");
}

void removeSeat(int n)
{
    if(passengers[n].reserved == 0)
    {
        printf("\n\t\t\tYou have not yet reserved a seat.\n");
        return;
    }

    char colLett;
    char ch;

    switch(passengers[n].collumnNumber)
    {
    case 1:
        colLett = 'A';
        break;
    case 2:
        colLett = 'B';
        break;
    case 3:
        colLett = 'C';
        break;
    case 4:
        colLett = 'D';
        break;
    case 5:
        colLett = 'E';
        break;
    case 6:
        colLett = 'F';
        break;
    }

    printf("\n\t\t\tYour current seat number: %d%c\n", passengers[n].rowNum, colLett);
    printf("\n\t\t\tAre you sure you want to remove your reservation? [Y/N]: ");
    scanf(" %c", &ch);
    fflush(stdin);

    if(ch == 'Y' || ch == 'y')
    {
        seats[passengers[n].rowNum-1][passengers[n].collumnNumber-1] = ' ';
        passengers[n].reserved = 0;
        passengers[n].rowNum = 0;
        passengers[n].collumnNumber = 0;
        printf("\n\t\t\tReservation removed.\n");
    }
    else
    {
        printf("\n\t\t\tOperation canceled.\n");
        return;
    }
}

void saveFile()
{
    FILE *fp = fopen("Passengers.txt", "w");
    char colLett;

    fprintf(fp, "Number of Passengers: %d\n", PassengerNum);
    for(int i=0; i<PassengerNum; i++)
    {
        switch(passengers[i].collumnNumber)
        {
        case 1:
            colLett = 'A';
            break;
        case 2:
            colLett = 'B';
            break;
        case 3:
            colLett = 'C';
            break;
        case 4:
            colLett = 'D';
            break;
        case 5:
            colLett = 'E';
            break;
        case 6:
            colLett = 'F';
            break;
        }
        fprintf(fp, "Passenger %d\n", i+1);
        fprintf(fp, "Full Name: %s\n", passengers[i].FullN);
        fprintf(fp, "Age: %d\n", passengers[i].age);
        fprintf(fp, "City: %s\n", passengers[i].city);
        if(passengers[i].reserved == 1)
        {
            fprintf(fp, "Seat Number: %d%c\n", passengers[i].rowNum, colLett);
        }
    }

    fclose(fp);
}


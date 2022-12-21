#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#pragma GCC diagnostic ignored "-Wwrite-strings"

int seat, Day, month, year, Class;
static int count = 1, count_note = 1;
char firstname[100], lastname[100], origin[100], destination[100], gender[7], meal, email[100], mobile[100];
int sandwich = 0, dosa = 0, vada = 0, pattice = 0, aloo = 0, c_sandwich = 0, omlette = 0, nuggets = 0, pakoda = 0, chicken_bbq = 0;

struct passenger
{
    char firstname[100], lastname[100], origin[100], destination[100], gender[7], meal, email[100], mobile[100];
    int age;
};

void notes(void);
void toShowList(void);
void toReserve(void);
void toSearchDate(void);
void toShowMatrix(void);
void toCalculate(void);
void toShowList(void);
void toCancel(void);
void toShowPrevious(void);
void toBookMeal(void);
void help(void);

const char *list[28] = {"Shimla", "Chandigarh", "Dehradun", "Delhi", "Gangtok", "Itanagar", "Jaipur", "Lucknow", "Dispur", "Kohima", "Patna", "Shillong", "Imphal", "Agartala", "Aizwal", "Ranchi", "Bhopal", "Gandhinagar", "Kolkata", "Raipur", "Amravati", "Bhuvaneshwar", "Mumbai", "Hyderabad", "Panaji", "Chennai", "Bengaluru", "Thiruvananthapuram"};

void menu(void)
{
    system("cls");
    int choice;
    printf ( "\033[0;33m" ) ;
    printf("\n------------------------ Welcome ------------------------\n\n");
    printf( "\033[0m" ) ;
    printf("1. Reserve a Seat\n\n2. Search for a Date\n\n3. Show the Seat Matrix\n\n4. Calculate the ticket fare\n\n5. Book a meal for the journey\n\n6. Add a note\n\n7. Show the list of stations availabe\n\n8. Cancel a Reservation\n\n9. Show the list of previously reserved seats\n\n10. HELP\n\n11. Exit");
    printf("\n\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
        int m;
    case 1:
        toReserve();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 2:
        toSearchDate();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 3:
        toShowMatrix();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 4:
        toCalculate();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 6:
        notes();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 7:
        toShowList();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 8:
        toCancel();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 9:
        toShowPrevious();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;
    case 10:
       help();
       printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
        menu();
        else
        break;

    case 11:
        exit(0);

    case 5:
        toBookMeal();
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            break;

    default:
        printf("Enter valid choice");
    }
}
const char *monthName(int m)
{
    switch (m)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    }
}
bool isLeap(int y)
{
    bool x = false;
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
        x = true;
    return x;
}

int whichDay(int m, int y)
{
    int yrCnt = 0;
    yrCnt = y - 2000 + (y - 2000) / 4;
    if (m == 1)
    {
        if (isLeap(y))
            return (yrCnt + 5) % 7;
        return (yrCnt + 6) % 7;
    }
    else if (m == 2)
    {
        if (isLeap(y))
            return (yrCnt + 1) % 7;
        return (yrCnt + 2) % 7;
    }
    else if (m % 2 == 0)
        return (yrCnt + 16 - m) % 7;
    else if (m == 3)
        return (yrCnt + 2) % 7;
    else if (m == 5)
        return (yrCnt) % 7;
    else if (m == 7)
        return (yrCnt + 5) % 7;
    else if (m == 9)
        return (yrCnt + 4) % 7;
    else if (m == 11)
        return (yrCnt + 2) % 7;
}

int day(int n, int y)
{
    if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
        return 31;
    else if (n == 4 || n == 6 || n == 9 || n == 11)
        return 30;
    else if (n == 2)
    {
        if (isLeap(y))
            return 29;
        else
            return 28;
    }
}

void pCal(int m, int y)
{
    printf("\n\tMonth: %s\tYear: %d\n", monthName(m), y);
    printf("\n\tMON TUE WED THU FRI SAT SUN\n");
    int d = 1, cnt = 0;
    for (int i = 0; i < 6; i++)
    {
        printf("\t");
        for (int j = 0; j < 7; j++)
        {
            if (whichDay(m, y) == j)
                cnt++;
            if (cnt > 0 && d <= day(m, y))
            {
                printf("%3d ", d);
                d++;
            }
            else
                printf("    ");
        }
        printf("\n");
    }
}

void toSearchDate(void)
{
    system("cls");
    int month_no, year;
    printf("Enter month number and year: ");
    scanf("%d%d", &month_no, &year);
    pCal(month_no, year);
}

void toReserve(void)
{
    system("cls");
    FILE *ptr_details = NULL;
    ptr_details = fopen("details.txt", "a");
    int num_of_pass;
    printf("Enter the number of passengers travelling together : ");
    scanf("%d", &num_of_pass);
    struct passenger people[num_of_pass];
    system("cls");
    printf("-----------------Travel Information-----------------\n");
    printf("The stations are mentioned as below :- \n");
    for (int i = 0; i < 10; i += 2)
        printf("%d)%-12s  %d)%s\n", i + 1, list[i], i + 2, list[i + 1]);
    for (int i = 10; i < 28; i += 2)
        printf("%d)%-11s  %d)%s\n", i + 1, list[i], i + 2, list[i + 1]);

    printf("\nEnter Origin : ");
    scanf("%s", origin);
    printf("Enter Destination : ");
    scanf("%s", destination);
    printf("\n\t1)Air-Conditioned Executive Chair Class\n\t2)Air-Conditioned First Class\n\t3)Air-Conditioned Two-Tier Class\n\t4)Air-Conditioned Three-Tier Class\n\t5)Non-Air-Conditioned First Class\n\t6)Sleeper Class\n\t7)Second Class\n\t8)Unreserved/General Class\n\nEnter the type of seat you want (1-8 in number): ");
    scanf("%d", &Class);
    printf("Enter the date of journey in dd/mm/yyyy format : ");
    scanf("%d/%d/%d", &Day, &month, &year);
    system("cls");

    for (int i = 0; i < num_of_pass; i++)
    {
        system("cls");
        printf("-----------------Personal Information-----------------\n");
        printf("Information of passenger number %d\n", (i + 1));
        printf("Enter first name of : ");
        scanf("%s", people[i].firstname);
        printf("Enter last name : ");
        scanf("%s", people[i].lastname);
        printf("Enter Age : ");
        scanf("%d", &people[i].age);
        printf("Enter Gender : ");
        scanf("%s", people[i].gender);
        printf("Enter email id : ");
        scanf("%s", people[i].email);
        printf("Enter mobile number : ");
        scanf("%s", people[i].mobile);
        fprintf(ptr_details, "Passenger Number %d\n", count);
        fprintf(ptr_details, "Name : %s %s\n", people[i].firstname, people[i].lastname);
        fprintf(ptr_details, "Age : %d\n", people[i].age);
        fprintf(ptr_details, "Gender : %s\n", people[i].gender);
        fprintf(ptr_details, "Email Id : %s\n", people[i].email);
        fprintf(ptr_details, "Mobile Number : %s\n", people[i].mobile);
        fprintf(ptr_details, "Origin : %s\n", origin);
        fprintf(ptr_details, "Destination : %s\n", destination);
        fprintf(ptr_details, "Type of Seat : %d\n", Class);
        fprintf(ptr_details, "Date : %d/%d/%d\n\n", Day, month, year);
        count++;
    }
    system("cls");
    printf("-----------------Ticket Confirmation-----------------\n");
    printf("YOUR TICKET(S) IS(ARE) CONFIRMED\n");
    printf("Train Name : %s - %s Express\n", origin, destination);
    printf("\nInorder to know the travel fare please go the menu");
    fclose(ptr_details);
}

void toDelete(void)
{
}

void toShowMatrix(void)
{
    const char *Seats[40] = { "A0", "B0", "C0", "D0", "A1", "B1", "C1", "D1", "A2", "B2", "C2", "D2", "A2", "B2", "C2", "D2", 
                              "A3", "B3", "C3", "D3", "A4", "B4", "C4", "D4", "A5", "B5", "C5", "D5", "A6", "B6", "C6", "D6",
                              "A7", "B7", "C7", "D7", "A8", "B8", "C9", "D9" };
    int Seat_Status[40] = {};
    printf("\t\tFRONT\n");
    printf ( "\033[0;36m" ) ;
    for (int i = 0; i < 40; i++)
    {
        if (Seat_Status[i] == 1)
        {
            printf("\033[0;31m");
            printf("|%s|", Seats[i]);
            printf("\033[0m");
        }
        else
            printf("|%s|", Seats[i]);

        if (((i + 1) % 2 == 0) && ((i + 1) % 4 != 0))
            printf("\t\t");
        else if ((i + 1) % 4 == 0)
            printf("\n");
        else 
            printf("\t");
    }
    printf( "\033[0m" ) ;
    printf("\t\tBACK\n"); 
}

void toCalculate(void)
{
    const char *list[28] = {"Shimla", "Chandigarh", "Dehradun", "Delhi", "Gangtok", "Itanagar", "Jaipur", "Lucknow", 
                            "Dispur", "Kohima", "Patna", "Shillong", "Imphal", "Agartala", "Aizwal", "Ranchi", "Bhopal", 
                            "Gandhinagar", "Kolkata", "Raipur", "Amravati", "Bhuvaneshwar", "Mumbai", "Hyderabad", "Panaji", 
                            "Chennai", "Bengaluru", "Thiruvananthapuram"};
    int distance[28] = { 0, 110, 227, 340, 1917, 2486, 681, 900, 2265, 2602, 1397, 2350, 2736, 2794, 2720, 1653, 1135, 
                         1245, 1904, 123, 1486, 709, 1746, 1928, 2252, 2553, 2520, 3202 };
    char pickup[20], drop[20];
    int age, AC = 0, m;
    printf("Enter the pickup location: ");
    scanf("%s", pickup);
    int a, b, i, j, fare;
    for(i = 0; i < 28; i++)
    {
        a = strcmpi(pickup, list[i]);
        if (a == 0)
            break;
    }
    if (a != 0)
    {
        printf("Match Not Found\n");
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            exit (0) ;
    }
    printf("Enter the drop location: ");
    scanf("%s", drop);
    for(j = 0; j < 28; j++)
    {
        b = strcmpi(drop, list[j]);
        if (b == 0)
            break;
    }
    if (b != 0)
    {
        printf("Match Not Found\n");
        printf("\nWant to go to menu (yes = 1 and no = 0) : ");
        scanf("%d", &m);
        if (m == 1)
            menu();
        else
            exit (0) ;
    }
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Want AC (1) or Non-AC (0) : ");
    scanf("%d", &AC);
    fare = 5 * (distance[i] - distance[j]);
    fare = abs(fare);
    if (age < 15)
        fare = fare - 150;
    if (AC == 1)
        fare = fare + 300;
    printf ( "\033[0;33m" ) ;
    printf("Total Fare = %d", fare);
    printf( "\033[0m" ) ;
}

void toCancel(void)
{
    char FirstName[100], LastName[100], seat[2];
    FILE *ptr_deleted;
    ptr_deleted = fopen("deleteds.txt", "a");
    fprintf(ptr_deleted, "The list of cancelled tickets are : \n");
    printf("Enter the First Name : ");
    scanf("%s", FirstName);
    printf("Enter the Last Name : ");
    scanf("%s", LastName);
    printf("Enter the seat number : ");
    scanf("%s", seat);
    printf("The seat reservation has been cancelled");
    fprintf(ptr_deleted, "\nName of the Passenger : %s %s", FirstName, LastName);
    fprintf(ptr_deleted, "\nSeat Number : %s", seat);

    fclose(ptr_deleted);
}

void toShowPrevious(void)
{
    system("cls");
    char *filename = "details.txt";
    FILE *fp = fopen("details.txt", "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
    }
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fp))
        printf("%s", buffer);
    fclose(fp);
}

void toShowList(void)
{
    system("cls");
    for (int i = 0; i < 28; i++)
        printf("%d) %s\n", i + 1, list[i]);
}

void notes()
{
    system("cls");
    FILE *fptr;
    int i, n, l;
    char str[1000];
    char fname[20] = "notes.txt";
    char str1;
    printf("If you want to add notes(enter 1) or read notes (enter 2) : ");
    scanf("%d", &l);
    if (l == 1)
    {
        printf(" Input the number of lines to be written : ");
        scanf("%d", &n);
        printf("--------------NOTES--------------\n");
        printf("write here....\n");
        fptr = fopen(fname, "a");
        for (i = 0; i < n + 1; i++)
        {
            fgets(str, sizeof str, stdin);
            fputs(str, fptr);
        }
        fclose(fptr);
    }
    /*-------------- read the file -------------------------------------*/
    else if (l == 2)
    {
        fptr = fopen(fname, "r");
        printf("\n-------------NOTES------------");
        str1 = fgetc(fptr);
        while (str1 != EOF)
        {
            printf("%c", str1);
            str1 = fgetc(fptr);
        }
        printf("\n\n");
        fclose(fptr);
    }

    else
        printf("wrong command");
}

void help(){
    printf("-----------HELP------------\n");
    printf("1) regarding ticket booking\n2) food related query\n3)regarding ticket cancellation\n4)list of stations, stops etc.\n5)genral rules to follow through the jouyrney\n6) other queries \n7) don't have any query ");
    printf("\nEnter the index number of query: ");
    int n;
    scanf("%d", &n);
    printf("Answer\n");
    switch(n){
        case 1:
        printf(" On the homepage enter 1(in response to enter your choice) for registration \nthen enter all the details asked correctly correctly");
        
        break;
        case 2:
        printf(" You can book meal for the journey\n");
        printf("\nYou have to just enter 5(in responce to Enter your choice) at the homepage and enter the further choices");
        printf("\nThe vegeterian menu includes :-\n1)Veg Sandwich : 100 Rupees\n2)Veg Dosa : 250 Rupees\n3)Veg Vada Pav : 20 Rupees\n4)Veg Ragda Pattice 60 Rupees\n5)Aloo Aur Shakarkand ki Chaat : 150 Rupees");
        printf("\nThe non-vegeterian menu includes :-\n1)Chicken Sandwich : 200 Rupees\n2)Omlette : 100 Rupees\n3)Chicken Nuggets : 100 Rupees\n4)Egg Pakoda 60 Rupees\n5)Chicken Barbeque : 350 Rupees");
        printf("\nNOTE : this meal booking will be active only if u have booked ticket already");
        break;
        case 3:
        printf("On the homepage enter 8(in response to Enter your choice) then fill the details asked correctly");
        break;
        case 4:
        printf("You can get the list of available stations by entering 7(in response to enter your choice) on the homepage\n");
        printf("\nu have to reach your starting city's HAPbuses office to board on the bus\n");
        printf("\nbus will only stop at selected stops in the citites and the last stop will be HAPbuses office in the respective city");
        break;
        case 5:
        printf("\n >smoking/alcoholing is banned inside the bus\n >donot make loud noises.\n >throw the garbage only in the provided dustbin\n");
        break;
        case 6:
        printf("please contact us through email HPAbuses@gmail.com");
        break;
        case 7:
        break;
        default:
        printf("please ask a valid querry");
        
    }
}

void toBookMeal(void)
{
    int total = 0;
    system("cls");
    int meal_items[5];
    int n, major, tot_items;
    printf("\nThe meal can only be booked after reserving a ticket");
    printf("\nIf not reserved any ticket enter 0 or else enter 1: ");
    scanf("%d", &n);
    if (n == 0)
        toReserve();
    else if (n == 1)
    {
        system("cls");
        printf("Welcome to FOOD ON TRACK meal booking system");
        printf("\nEnter your preferences according the given choices :-");
        printf("\n1)Vegeterian Meal\n2)Non-Vegeterian Meal\nEnter your choice (1 or 2)\n");
        printf("Your choice : ");
        scanf("%d", &major);
        system("cls");
        if (major == 1)
        {
            printf("The vegeterian menu includes :-\n1)Veg Sandwich : 100 Rupees\n2)Veg Dosa : 250 Rupees\n3)Veg Vada Pav : 20 Rupees\n4)Veg Ragda Pattice 60 Rupees\n5)Aloo Aur Shakarkand ki Chaat : 150 Rupees");
            printf("\nEnter the total number of items you wish to have in the journey : ");
            scanf("%d", &tot_items);
            printf("\nEnter the index number of the item you wish to have in the journey (giving space between the integers):\n");
            for (int i = 0; i < tot_items; i++)
                scanf("%d", &meal_items[i]);
            for (int j = 0; j < tot_items; j++)
            {
                if (meal_items[j] == 1)
                {
                    sandwich++;
                    total += 100;
                }
                else if (meal_items[j] == 2)
                {
                    dosa++;
                    total += 250;
                }
                else if (meal_items[j] == 3)
                {
                    vada++;
                    total += 20;
                }
                else if (meal_items[j] == 4)
                {
                    pattice++;
                    total += 60;
                }
                else if (meal_items[j] == 5)
                {
                    aloo++;
                    total += 150;
                }
            }
            system("cls");
            printf("Your meal is confirmed");
            printf("\nThe total amount payable is : %d Rupees", total);
        }

        else if (major == 2)
        {
            system("cls");
            printf("The non-vegeterian menu includes :-\n1)Chicken Sandwich : 200 Rupees\n2)Omlette : 100 Rupees\n3)Chicken Nuggets : 100 Rupees\n4)Egg Pakoda 60 Rupees\n5)Chicken Barbeque : 350 Rupees");
            printf("\nEnter the total number of items you wish to have in the journey : ");
            scanf("%d", &tot_items);
            printf("\nEnter the index number of the item you wish to have in the journey (giving space between the integers):\n");
            for (int i = 0; i < tot_items; i++)
                scanf("%d", &meal_items[i]);
            for (int j = 0; j < tot_items; j++)
            {
                if (meal_items[j] == 1)
                {
                    c_sandwich++;
                    total += 200;
                }
                else if (meal_items[j] == 2)
                {
                    omlette++;
                    total += 100;
                }
                else if (meal_items[j] == 3)
                {
                    nuggets++;
                    total += 100;
                }
                else if (meal_items[j] == 4)
                {
                    pakoda++;
                    total += 60;
                }
                else if (meal_items[j] == 5)
                {
                    chicken_bbq++;
                    total += 350;
                }
            }
            system("cls");
            printf("Your meal is confirmed");
            printf("\nThe total amount payable is : %d Rupees", total);
        }
    }
}

int main()
{
    system("cls");
    int i, c = 0;
    char ch1, password[10], correct[10] = "Project";
    printf("Enter your password:");
    for (i = 0; i < 10; i++)
    {
        ch1 = getch();
        password[i] = ch1;

        if (ch1 != 13)
            printf("*");
        if (ch1 == 13)
            break;
    }

    password[i] = '\0';
    if (strcmp(password, correct) == 0)
        menu();

    else
        printf("\nWRONG PASSWORD");

    return 0;
}
#pragma GCC diagnostic pop
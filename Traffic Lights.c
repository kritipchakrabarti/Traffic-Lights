#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int red, yellow, green;

}Traffic;

Traffic east, west, north, south;

int delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
        return 1;
}

void change_yellow()
{
    if(east.green==1)
    {
        east.green=0;
        east.yellow=1;
        east.red=0;

        west.green=0;
        west.yellow=1;
        west.red=0;
    }

    if(south.green==1)
    {
        south.green=0;
        south.yellow=1;
        south.red=0;

        north.green=0;
        north.yellow=1;
        north.red=0;
    }
}

void change_red()
{
    if(east.yellow==1)
    {
        east.red=1;
        east.yellow=0;
        east.green=0;

        west.red=1;
        west.yellow=0;
        west.green=0;

        north.red=0;
        north.yellow=0;
        north.green=1;

        south.red=0;
        south.yellow=0;
        south.green=1;

    }
    if(south.yellow==1)
    {
        east.red=0;
        east.yellow=0;
        east.green=1;

        west.red=0;
        west.yellow=0;
        west.green=1;

        north.red=1;
        north.yellow=0;
        north.green=0;

        south.red=1;
        south.yellow=0;
        south.green=0;

    }
}

void print()
{
    system("cls");
    printf("\t\t\t");
    if(north.red==1)
        printf("RED");
    if(north.yellow==1)
        printf("Yellow");
    if(north.green==1)
        printf("GREEN");

    printf("\n");
    if(west.red==1)
        printf("RED");
    if(west.yellow==1)
        printf("Yellow");
    if(west.green==1)
        printf("GREEN");

    printf("\t\t\t\t\t\t");
    if(east.red==1)
        printf("RED");
    if(east.yellow==1)
        printf("Yellow");
    if(east.green==1)
        printf("GREEN");

        printf("\n\t\t\t");
    if(south.red==1)
        printf("RED");
    if(south.yellow==1)
        printf("Yellow");
    if(south.green==1)
        printf("GREEN");

         char ch;
        printf("\n\nPress Enter to continue and Space + Enter to exit\n");
        scanf("%c",&ch);
        if(ch!=10)
            exit(0);
}

int main()
{
    east.yellow=west.yellow=south.yellow=north.yellow=0;
    east.red= west.red=0;
    east.green=west.green=1;
    north.red=south.red=1;
    north.green=south.green=0;

    print();

    while(1)
    {
        delay(10);
        change_yellow();
        print();

        delay(3);
        change_red();
        print();

    }


}



#include<stdlib.h>
#include<stdio.h>
int get_1st_weekday(int year) //To find the starting day of the month
{
    int day;
    day=(((year-1)+365)+((year-1)/4)-((year-1)/100)+((year/400)+1))%7;  
    return day;
}
int main()
{ 
    system("color 3F"); //color of the terminal
    int year,month,day,daysInMonth,weekDay=0,startingDay;
    printf("\nEnter your desire year:");
    scanf("%d",&year);

    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31}; //Day in the month
    if((year%4==0 && year%100!=0)||year%400==0) //To check the leap year
    monthDay[1]=29; //if leap year match then month[1] change to 29 days
    
    startingDay=get_1st_weekday(year); //start the day in the month by call the function.
    for(month=0;month<12;month++)
    {
        daysInMonth=monthDay[month];
        printf("\n\n------------------%s------------------\n",months[month]);
        printf("\n   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for(weekDay=0;weekDay<startingDay;weekDay++) //To create a space
        printf("     ");

        for(day=1;day<=daysInMonth;day++) //To fill the day on the month
        {
            printf("%5d",day);
            if(++weekDay>6) //To ceate new line after the end of the weeks
            {
            printf("\n");
            weekDay=0;
            }
            startingDay=weekDay; //initailized the startingDay with weekDay value
        }

    }
return 0;
}
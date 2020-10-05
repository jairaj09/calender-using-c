#include <stdio.h>
#include <stdlib.h>
#include<string.h>


      //For the month name

char *monthname(int monthnumber)
{
  char *month ;
  switch (monthnumber)
  {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
     default : "Wrong Month";
     break ;
  }
  return month;
}

  //FOR NUMBER OF DAYS IN THE MONTH

  int daysinmonth(int monthnumber , int year)
  {
   int days ;
    if(monthnumber ==1 )
        {
       days=31 ;
    }
       if(monthnumber ==2 )
        {
           if((year%4==0) && (year%400==0 || year%100!=0))
               days=29;
           else
               days=28;
        }
        if(monthnumber ==3 )
        {
            days=31 ;
        }
        if(monthnumber ==4 )
        {
            days=30;
        }
        if(monthnumber==5 )
        {
            days=31;
        }
        if(monthnumber ==6 )
        {
            days=30;
        }
        if(monthnumber ==7 )
        {
            days=31;
        }
        if(monthnumber ==8 )
        {
           days=31;
        }
        if(monthnumber ==9 )
        {
            days=30;
        }
        if(monthnumber ==10)
        {
           days=31;
        }
        if(monthnumber ==11 )
        {
            days=30;
        }
        if(monthnumber==12 )
        {
            days=31;
        }
        return days;
  }


  //for finding the daycode 
int daycode(int monthnumber, int year)
{
     int daynumber=1;
        year = year - (monthnumber < 3);
     int monthcode[] = {0, 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    return (year + year / 4+ year / 400- year / 100+ monthcode[monthnumber] + daynumber)% 7;
}


    //For printing calender of a single month of a year;

    void monthcalender(int monthnumber,int year)
{
    int x = daycode(monthnumber,year);
    int day , i ;

     printf("\n           %s-%d              \n",monthname(monthnumber),year);
     printf("\n   SUN  MON  TUE  WED  THU  FRI  SAT\n");

    for(i=0;i<x;i++)
        {
        printf("    -");

        }
        for(day=1;day<=daysinmonth(monthnumber,year);day++){
             printf("%5d",day);
             if(++i > 6)
             {
                 i=0;
                printf("\n");
             }
                                                            }
}

//For printing the day of a particular date

void dayofweek(int day,int monthnumber,int year)
{
    int y;
   year = year - (monthnumber < 3);
     int monthcode[] = {0, 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y = (year + year / 4+ year / 400- year / 100+ monthcode[monthnumber] + day)% 7;
    printf("\nThe day on %d-%d-%d is : ",day,monthnumber,year);
    switch (y)
    {
        case 0 : printf("Sunday");
        break;
        case 1 : printf("Monday");
        break;
        case 2 : printf("Tuesday");
        break;
        case 3 : printf("Wednesday");
        break;
        case 4 : printf("Thursday");
        break;
        case 5 : printf("Friday");
        break;
        case 6 : printf("Saturday");
        break;
    }
}


int main()
{   printf("\nAdd note if any else enter No : ");
    char n[200];
    fgets(n, 200, stdin);
    int a ,b ,c ;
    int d ,m,y;
    int year , monthnumber , day;

    printf("\nIf you have added a note.Enter 1 else Enter 0: ");
    scanf("%d",&a);
    if(a==1)
    {
        printf("\nEnter the date at which you want to add the note dd-mm-yyyy : ");
        scanf("%d-%d-%d",&day,&monthnumber ,&year);
        d=day;
        m=monthnumber;
        y=year;
    }
    printf("\nWant to print the calender of a single month.If yes enter 1 : ");
    scanf("%d",&c);
    if(c==1)
    {
    printf("\nEnter month and year for the calender .\n");
    printf("\nEntr mm-yyyy : ");
    scanf("%d-%d",&monthnumber,&year);
    monthcalender(monthnumber,year);
    if((monthnumber==m)&&(year==y))
    {
        printf("\n   %d-%d-%d : %s" ,d,m,y,n);
    }

    }


      printf("\nWant to find out day of a particular date?? If yes enter 1 : ");
      scanf("%d",&b);
      if (b==1)
      {
        printf("\nEnter dd-mm-yyyy : ");
        scanf("%d-%d-%d",&day,&monthnumber,&year);
        dayofweek(day , monthnumber , year);
      }

    printf("\n\nThat was all .Have a nice day.\n");

  return 0;
}

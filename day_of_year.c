#include<stdio.h>
#include<conio.h>
#include<string.h>
int day_of_year(int year,int month,int day);

main()
{
      int year,month,day;
      int year_day;
      printf("enter year ,month ,day");
      scanf("%d%d%d",&year,&month,&day);
      year_day = day_of_year(year,month,day);
        
     printf("%d" ,year_day);

getch();
return 0;
}

int day_of_year(int year,int month,int day)
{
    int daytab[][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
                int i,leap;
                leap = year%4==0 && year%100 !=0 || year%400 ==0;
                for(i=1;i<month;i++)
                day = day + (*(*(daytab+leap)+i));
                return day;
                }


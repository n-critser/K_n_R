#include<stdio.h>

static char daytab[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day){
        int i, leap;
        leap = (year%4 == 0) && (year%100 !=0 || year % 400 ==0);
        for (i =1; i < month; i++)
                day += daytab[leap][i];
        return day;
}

/* using pointers instead of multiple return values */
void month_day(int year, int yearday, int *pmonth, int *pday){
        int i, leap;
        leap =  (year%4 == 0) && (year%100 !=0 || year % 400 ==0);
        for (i =1; yearday > daytab[leap][i]; i++)
                yearday -= daytab[leap][i];
        *pmonth=i;
        *pday=yearday;
}

char *month_name(int n){
        static char *name[]={
                "Illegal",
                "January",
                "February","March","April","May","June","July",
                "August","September","October","November","December"
        };
        return (n <1 || n>12) ? name[0] : name[n];
}

int main(void){

        int year,month,day,yearday,*pmon,*pday;
        char*moName;
        year = 2015;
        month= 3;
        day=1;
        yearday=0;
        printf("yearday=%d\n",(yearday=day_of_year(year,month,day)));
        
        pmon=&month;
        pday=&day;
        month_day(year,yearday,pmon,pday);
        printf("month:%d--%s , day:%d\n",*pmon,(moName=month_name(*pmon)),*pday);
        return 0;
        
}

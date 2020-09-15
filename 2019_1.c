#include <stdio.h>
#include <windows.h>

/* 求某年某月某日为星期几(已知1.1.1为周一) */

int get_weekday(int year, int month, int day);
int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
char weekday[7][4]={"Sun","Mon","Tue","Wen","Thu","Fri","Sat"};

int main(void){

    int year, month, day;

    while(1){
        fputs("Date:",stdout);
        scanf("%4d %2d %2d",&year,&month,&day);
        
        printf("%d.%d.%d: ",year,month,day);

        int a=get_weekday(year, month, day);
        printf("%s\n",weekday[a]);
    }

    return 0;
}

int get_weekday(int year, int month, int day){
    //1.1.1--Mon
    int day_num=0;
    for(int y=1;y<year;y++){
        if(y%400==0){
            day_num+=366;
        }
        else if(y%100!=0 && y%4==0){
            day_num+=366;
        }
        else{
            day_num+=365;
        }
    }
    if (year%400==0)
    {
        for (int i = 0; i < month-1; i++)
        {
            day_num+=run[i];
        }
    }
    else if(year%100!=0 && year%4==0){
        for (int i = 0; i < month-1; i++)
        {
            day_num+=run[i];
        }
    }
    else{
        for (int i = 0; i < month-1; i++)
        {
            day_num+=ping[i];
        }
    }
    day_num+=day;

    return day_num%7;
}
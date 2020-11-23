/* 求某年某月某日为星期几(已知1.1.1为周一) */

#include <stdio.h>
#include <windows.h>

int get_weekday(int year, int month, int day);

int main(void)
{

    int year, month, day;
    fputs("Date:", stdout);
    scanf("%4d %2d %2d", &year, &month, &day);

    printf("%d.%d.%d: ", year, month, day);
    printf("%d\n", get_weekday(year, month, day));

    return 0;
}

int get_weekday(int year, int month, int day)
{
    // 1.1.1--Mon
    // 1.2.1--Thu
    // 2020.11.23--Mon
    int day_sum = 0;
    // 计算当年前n年的总天数
    for (int i = 1; i < year; i++)
    {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
        {
            day_sum += 366;
        }
        else
        {
            day_sum += 365;
        }
    }
    // 计算当月前n月的天数(最后一个月直接加即可)
    for (int i = 1; i < month; i++)
    {
        if (i == 2)
        {
            // 如果是闰年
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                day_sum += 29;
            }
            else
            {
                day_sum += 28;
            }
        }
        else
        {
            switch (i)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                day_sum += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                day_sum += 30;
                break;
            default:
                break;
            }
        }
    }
    day_sum += day;

    return (day_sum % 7 == 0) ? 7 : (day_sum % 7);
}
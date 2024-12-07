#include <stdio.h>
#include <math.h>
#include <string.h> // strtok
#include <stdlib.h> // atoi

char date1[100], date2[100];
int count = 0;

int yearStart, monthStart, dayStart = 0;
int yearStop, monthStop, dayStop = 0;

void getDate(char* date, int* year, int* month, int* day)
{
    const char delimiter[] = "-";  // 定義分隔符
    char *token;

    // 使用 strtok 分割字串
    token = strtok(date, delimiter);

    if (token != NULL)
    {
        *year = atoi(token);  // 將字串轉換為整數
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        *month = atoi(token);
    }


    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        *day = atoi(token);
    }

    //return year, month, day;//不能return多個值!!
}

int dayOfYear(int year, int month, int day)
{
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//exclude leap year

    if (isLeapYear(year))
    {
        days_in_month[1] = 29;  // 閏年二月有 29 天
    }

    int total_days = 0;

    for (int i = 0; i < month - 1; i++)
    {
        total_days += days_in_month[i];
    }

    total_days += day;

    return total_days;
}

int isLeapYear(int year) 
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        return 1;  // 閏年
    }

    return 0;      // 平年
}

void calculate(int days1, int days2)
{
    int daysBetween = 0;

    if(yearStart == yearStop)
    {
        daysBetween = days2 - days1;
    }
    else
    {
        if(isLeapYear(yearStart) == 1)
        {
            daysBetween += 366 - days1 + days2;
        }
        else
        {
            daysBetween += 365 - days1 + days2;
        }
        
        for(int i = yearStart + 1; i < yearStop; i++)
        {
            daysBetween += isLeapYear(i) ? 366 : 365;//很簡潔!!
            //如果中間跨的年份有閏年則那一年為366天
            //其他一律為正常年，皆為365天
        }
        
    }

    printf("%d", daysBetween);
}

int main()
{
    scanf("%s", date1);
    scanf("%s", date2);

    getDate(date1, &yearStart, &monthStart, &dayStart);
    getDate(date2, &yearStop, &monthStop, &dayStop);

    int days1 = dayOfYear(yearStart, monthStart, dayStart);
    int days2 = dayOfYear(yearStop, monthStop, dayStop);

    calculate(days1, days2);

    return 0;
}
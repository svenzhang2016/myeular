// You are given the following information, but you may prefer to do some research for yourself.

// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <iostream>

using namespace std;

int main()
{
    int days = 1, years = 1900;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sundays = 0;
    while(years < 2001)
    {
        for(int i = 0; i < 12; i++)
        {
            days += months[i];
            if(i == 1 && (years%4==0&&years%100!=0 || years%400==0))
            {
                days += 1;
            }
            if(days%7==0&&years>=1901)
            {
                sundays++;
            }
        }
        years++;
    }
    cout << sundays << endl;
}
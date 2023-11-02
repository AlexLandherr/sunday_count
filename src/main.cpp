#include "include/functions.h"
#include <iostream>
#include <vector>

/*
You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.

- Thirty days has September, April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.

- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

int main() {
    std::vector<int> test_years = {1600, 1700, 1800, 1900, 2000, 2012, 2100, 2200, 2300};
    for (int y : test_years) {
        std::cout << "Is " << y << " a leap year?: " << func::is_leap_year(y) << '\n';
    }

    return 0;
}
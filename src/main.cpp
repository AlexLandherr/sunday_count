#include "include/functions.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

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
    /* std::vector<int> test_years = {1600, 1700, 1800, 1900, 2000, 2012, 2100, 2200, 2300};
    for (int y : test_years) {
        std::cout << "Is " << y << " a leap year?: " << func::is_leap_year(y) << '\n';
    } */
    //Setting start date for search.
    std::tm tm_start_date = {};
    std::stringstream start_date_str_stream("1901-01-01");
    start_date_str_stream >> std::get_time(&tm_start_date, "%Y-%m-%d");
    auto start_date_tp = std::chrono::system_clock::from_time_t(std::mktime(&tm_start_date));

    /* std::cout << func::write_time(func::add_months(start_date_tp, 1)) << '\n';
    std::cout << "Is " << func::write_time(func::add_months(start_date_tp, 1)) << " a Tuesday?: "
    << func::is_given_weekday(start_date_tp, std::chrono::Tuesday) << '\n'; */

    /* std::cout << "Is " << func::write_time(start_date_tp) << " a Sunday?: "
    << func::is_given_weekday(start_date_tp, std::chrono::Sunday) << '\n'; */
    int sunday_counter = 0;
    for (int m = 0; m <= 1200; m++) {
        /* std::cout << "Is " << func::write_time(func::add_months(start_date_tp, m)) << " a Sunday?: "
        << func::is_given_weekday(func::add_months(start_date_tp, m), std::chrono::Sunday) << '\n'; */
        if (func::is_given_weekday(func::add_months(start_date_tp, m), std::chrono::Sunday)) {
            sunday_counter++;
        }
    }
    std::cout << "The number of Sundays that fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000) is:" << '\n';
    std::cout << sunday_counter << '\n';

    //Setting stop date for search.
    /* std::tm tm_stop_date = {};
    std::stringstream stop_date_str_stream("2000-12-31");
    stop_date_str_stream >> std::get_time(&tm_stop_date, "%Y-%m-%d");
    auto stop_date_tp = std::chrono::system_clock::from_time_t(std::mktime(&tm_start_date)); */

    return 0;
}
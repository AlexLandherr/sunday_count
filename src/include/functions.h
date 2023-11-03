#include <chrono>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    /* bool is_leap_year(int year); */
    std::chrono::system_clock::time_point add_months(std::chrono::system_clock::time_point tp, int month_count);
    std::string write_time(std::chrono::system_clock::time_point intime);
    bool is_given_weekday(std::chrono::system_clock::time_point intime, std::chrono::weekday wd);
}

#endif
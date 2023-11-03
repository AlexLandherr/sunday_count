#include "include/functions.h"
#include <chrono>
#include <string>
#include <ctime>
#include <iomanip>

namespace func {
    /* bool is_leap_year(int year) {
        if (year % 400 == 0) {
            return true;
        } else if (year % 100 == 0) {
            return false;
        } else if (year % 4 == 0) {
            return true;
        } else {
            return false;
        }
    } */

    std::chrono::system_clock::time_point add_months(std::chrono::system_clock::time_point tp, int month_count) {
        // Get a days-precision chrono::time_point
        auto sd = std::chrono::floor<std::chrono::days>(tp);
        // Record the time of day
        auto time_of_day = tp - sd;
        // Convert to a y/m/d calendar data structure
        std::chrono::year_month_day ymd = sd;
        // Add the months
        ymd += std::chrono::months{month_count};
        // Add some policy for overflowing the day-of-month if desired
        if (!ymd.ok())
            ymd = ymd.year()/ymd.month()/std::chrono::last;
        // Convert back to system_clock::time_point
        std::chrono::system_clock::time_point later = std::chrono::sys_days{ymd} + time_of_day;
        return later;
    }

    std::string write_time(std::chrono::system_clock::time_point intime) {
        std::stringstream ss;
   
        std::time_t time = std::chrono::system_clock::to_time_t(intime);
        //ss << std::put_time(std::localtime(&time), "%F %T");
        ss << std::put_time(std::localtime(&time), "%F");
   
        return ss.str();
    }

    bool is_given_weekday(std::chrono::system_clock::time_point intime, std::chrono::weekday wd) {
        std::chrono::weekday intime_wd{std::chrono::floor<std::chrono::days>(intime)};
        return intime_wd == wd;
    }
}
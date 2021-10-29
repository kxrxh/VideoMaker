#pragma once

#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

// format number like: "2" -> "02"
std::string to_format(const int number)
{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << number;
    return ss.str();
}

// round function
double round_up(double value,  const int decimal_places)
{
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}
// replace funciton
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

// Formating time
template<typename T>
void timeFormat(T& strct)
{
    strct.min += strct.sec / 60;
    strct.sec %= 60;

    strct.hour += strct.min / 60;
    strct.min %= 60;
}

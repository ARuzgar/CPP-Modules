#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int main(int ac, char **av)
{
    float positive_infinity = INFINITY;
    float negative_infinity = -INFINITY;
    float nan_value = NAN;

    std::cout << "Positive Infinity Float: " << positive_infinity << std::endl;
    std::cout << "Negative Infinity Float: " << negative_infinity << std::endl;
    std::cout << "NaN Float: " << nan_value << std::endl;

    std::cout << std::endl;

    double positive_infinity_double = INFINITY;
    double negative_infinity_double = -INFINITY;
    double nan_value_double = NAN;

    std::cout << "Positive Infinity Double: " << positive_infinity_double << std::endl;
    std::cout << "Negative Infinity Double: " << negative_infinity_double << std::endl;
    std::cout << "NaN Double: " << nan_value_double << std::endl;

    std::cout << std::endl;




    return (0);
}
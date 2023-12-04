#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }
    else
        try
        {
            ScalarConverter::convert(av[1]);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    return (0);
}

/*     char positive_infinity_char = INFINITY;
    char negative_infinity_char = -INFINITY;
    char nan_value_char = NAN;

    std::cout << "Positive Infinity Char: " << positive_infinity_char << std::endl;
    std::cout << "Negative Infinity Char: " << negative_infinity_char << std::endl;
    std::cout << "NaN Char: " << nan_value_char << std::endl;

    std::cout << std::endl;

    int positive_infinity_int = INFINITY;
    int negative_infinity_int = -INFINITY;
    int nan_value_int = NAN;

    std::cout << "Positive Infinity Int: " << positive_infinity_int << std::endl; //Some Weird behiavor here
    std::cout << "Negative Infinity Int: " << negative_infinity_int << std::endl;
    std::cout << "NaN Int: " << nan_value_int << std::endl;

    std::cout << std::endl;

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
 */
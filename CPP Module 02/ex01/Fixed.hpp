#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed{

private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const int intToFix);
	Fixed(const float floatToFix);
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &number);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed{

private:

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &number);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
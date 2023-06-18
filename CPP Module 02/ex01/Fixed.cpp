#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int intToFix)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = intToFix << bits;
}

Fixed::Fixed(const float floatToFix)
{
	std::cout << "Float constructor called" << std::endl;
	float scaleFactor = pow(2, bits);
    float scaledValue = value * scaleFactor;
    int roundedValue = static_cast<int>(roundf(scaledValue));
    this->value = roundedValue << bits;
}

Fixed & Fixed::operator=(const Fixed &number)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->value = number.value;
	return (*this);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}
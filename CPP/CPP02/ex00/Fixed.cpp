#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called." << std::endl;
	this->value = other.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Assignation operator called." << std::endl;
	
}
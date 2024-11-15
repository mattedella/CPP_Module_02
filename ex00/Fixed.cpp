
#include "Fixed.hpp"

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return _num;
}

void Fixed::setRawBits(int const raw) {
	_num = raw;
}

Fixed::Fixed(void) : _num(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& num) {
	this->setRawBits(num.getRawBits());
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& num) {
	std::cout << "Copy assigment operator called\n";
	if (this != &num)
		this->setRawBits(num.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

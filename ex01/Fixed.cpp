
#include "Fixed.hpp"

int Fixed::getRawBits(void) const {
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

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	_num = num << _fractional_bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	_num = roundf(num * (1 << _fractional_bits));
}

Fixed& Fixed::operator=(const Fixed& num) {
	std::cout << "Copy assigment operator called\n";
	if (this != &num)
		this->setRawBits(num.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& num) {
	out << num.toFloat();
	return out;
}

float Fixed::toFloat(void) const {
	return (float)(_num) / (1 << _fractional_bits); 
}

int Fixed::toInt(void) const {
	return _num >> _fractional_bits;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

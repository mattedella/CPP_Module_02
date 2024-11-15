
#include "Fixed.hpp"

Fixed::Fixed(void) : _num(0) {
}

Fixed::Fixed(const Fixed& num) {
	this->setRawBits(num.getRawBits());
}

Fixed::Fixed(const int num) {
	_num = num << _fractional_bits;
}

Fixed::Fixed(const float num) {
	_num = roundf(num * (1 << _fractional_bits));
}

int Fixed::getRawBits(void) const {
	return _num;
}

void Fixed::setRawBits(int const raw) {
	_num = raw;
}

Fixed Fixed::operator*(const Fixed& num) const {
	Fixed ret;

	ret.setRawBits((this->_num * num._num) >> _fractional_bits);
	return ret;
}

Fixed Fixed::operator+(const Fixed& num) const {
	Fixed ret;

	ret.setRawBits(this->_num + num._num);
	return ret;
}

Fixed Fixed::operator-(const Fixed& num) const {
	Fixed ret;

	ret.setRawBits(this->_num - num._num);
	return ret;
}

Fixed Fixed::operator/(const Fixed& num) const {
	Fixed ret;

	if (num._num == 0) {
		std::cout << "Error: division by zero\n";
		return ret;
	}
	ret.setRawBits((this->_num << _fractional_bits) / num._num);
	return ret;
}

Fixed& Fixed::operator=(const Fixed& num) {
	if (this != &num)
		this->setRawBits(num.getRawBits());
	return *this;
}

Fixed& Fixed::operator++() {
	++_num;
	return *this;
}

Fixed& Fixed::operator--() {
	--_num;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++_num;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--_num;
	return tmp;
}

bool Fixed::operator<(const Fixed& num) const {
	return _num < num._num;
}

bool Fixed::operator>(const Fixed& num) const {
	return _num > num._num;
}

bool Fixed::operator<=(const Fixed& num) const {
	return _num <= num._num;
}

bool Fixed::operator>=(const Fixed& num) const {
	return _num >= num._num;
}
bool Fixed::operator==(const Fixed& num) const {
	return _num == num._num;
}
bool Fixed::operator!=(const Fixed& num) const {
	return _num != num._num;
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

Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
	return (num1 < num2) ? num1 : num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
	return (num1 < num2) ? num1 : num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	return (num1 > num2) ? num1 : num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
	return (num1 > num2) ? num1 : num2;
}

Fixed::~Fixed(void) {
}

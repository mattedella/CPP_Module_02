#ifndef FIXED
# define FIXED

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int _num;
		static const int _fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& num);
		Fixed(const int num);
		Fixed(const float num);

		Fixed& operator=(const Fixed& num);
		Fixed operator+(const Fixed& num) const;
		Fixed operator-(const Fixed& num) const;
		Fixed operator*(const Fixed& num) const;
		Fixed operator/(const Fixed& num) const;

		bool operator<(const Fixed& num) const;
		bool operator>(const Fixed& num) const;
		bool operator<=(const Fixed& num) const;
		bool operator>=(const Fixed& num) const;
		bool operator==(const Fixed& num) const;
		bool operator!=(const Fixed& num) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);


		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& num1, Fixed& num2);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
		static Fixed&		max(Fixed& num1, Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);

		void setRawBits(int const raw);

		int getRawBits(void) const;

		~Fixed(void);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& num);

#endif
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

		Fixed&			operator=(const Fixed& num);

		float	toFloat(void) const;
		int		toInt(void) const;

		void setRawBits(int const raw);

		int getRawBits(void) const;

		~Fixed(void);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& num);

#endif
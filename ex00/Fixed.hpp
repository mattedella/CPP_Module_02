#ifndef FIXED
# define FIXED

#include <iostream>

class Fixed {

	private:
		int 				_num;
		static const int	_fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& num);

		Fixed& operator=(const Fixed& num);

		void setRawBits(int const raw);
		int getRawBits(void) const;

		~Fixed(void);
};

#endif
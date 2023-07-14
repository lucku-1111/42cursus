#ifndef FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& f);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);
		Fixed&			operator=(const Fixed& f);
		std::ostream&	operator<<(std::ostream &out, const Fixed& fixed);
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
};

#endif
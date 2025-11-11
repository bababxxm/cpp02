/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:52 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/11 14:12:04 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{

	private:

		int					_fixed_point;
		static const int	_fractional_bits;
	
	public:

		Fixed( void );
		Fixed( int raw );
		Fixed( float raw );
		Fixed( const Fixed& other );
		~Fixed( void );

		void	setRawBits( int raw );
		int		getRawBits( void ) const;
		int 	toInt( void ) const;
		float	toFloat( void ) const;
		
		Fixed&	operator=( const Fixed& other );

		Fixed&	operator++( void );
		Fixed&	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		Fixed	operator+( const Fixed& other );
		Fixed	operator-( const Fixed& other );
		Fixed	operator*( const Fixed& other );
		Fixed	operator/( const Fixed& other );

		bool	operator>( const Fixed& other ) const;
		bool	operator<( const Fixed& other ) const;
		bool	operator>=( const Fixed& other ) const;
		bool	operator<=( const Fixed& other ) const;
		bool	operator==( const Fixed& other ) const;
		bool	operator!=( const Fixed& other ) const;

		static Fixed&	min( Fixed& a, Fixed& b );
		static Fixed&	max( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream&	operator<<( std::ostream &os, const Fixed& other );

#endif

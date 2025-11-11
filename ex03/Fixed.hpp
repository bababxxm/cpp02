/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:52 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/11 14:01:38 by sklaokli         ###   ########.fr       */
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
		static const float	_epsilon;
	
	public:

		Fixed( void );
		Fixed( int n );
		Fixed( float f );
		Fixed( const Fixed& other );
		~Fixed( void );
		
		Fixed&	operator=( const Fixed& other );
		Fixed&	operator=( int n );
		Fixed&	operator=( float f );

		Fixed	operator+( const Fixed& other ) const;
		Fixed	operator-( const Fixed& other ) const;
		Fixed	operator*( const Fixed& other ) const;
		Fixed	operator/( const Fixed& other ) const;

		Fixed 	operator+( int n ) const;
    	Fixed 	operator-( int n ) const;
    	Fixed 	operator*( int n ) const;
    	Fixed 	operator/( int n ) const;

		Fixed 	operator+( float f ) const;
    	Fixed 	operator-( float f ) const;
    	Fixed 	operator*( float f ) const;
    	Fixed 	operator/( float f ) const;

		Fixed&	operator++( void );
		Fixed&	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		bool	operator>( const Fixed& other ) const;
		bool	operator<( const Fixed& other ) const;
		bool	operator>=( const Fixed& other ) const;
		bool	operator<=( const Fixed& other ) const;
		bool	operator==( const Fixed& other ) const;
		bool	operator!=( const Fixed& other ) const;

		bool	operator>( int n ) const;
    	bool	operator<( int n ) const;
    	bool	operator>=( int n ) const;
    	bool	operator<=( int n ) const;
    	bool	operator==( int n ) const;
    	bool	operator!=( int n ) const;

		bool	operator>( float f ) const;
		bool	operator<( float f ) const;
		bool	operator>=( float f ) const;
		bool	operator<=( float f ) const;
		bool	operator==( float f ) const;
		bool	operator!=( float f ) const;

		void	setRawBits( int raw );
		int		getRawBits( void ) const;
		int 	toInt( void ) const;
		float	toFloat( void ) const;

		bool	isZero( void ) const;
		Fixed	abs( void ) const;
		const Fixed&	min( const Fixed& a, const Fixed& b );
		const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream&	operator<<( std::ostream &os, const Fixed& fp );

#endif

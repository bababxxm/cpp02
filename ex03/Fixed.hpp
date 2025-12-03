/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:52 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 15:59:12 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed {

	private:

		int					_rawBits;
		static const int	_fractionalBits;
		static const float	_epsilon;
	
	public:

		Fixed( void );
		Fixed( int n );
		Fixed( float f );
		Fixed( const Fixed& other );
		~Fixed( void );

		void	setRawBits( int raw );
		int		getRawBits( void ) const;

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

		int 	toInt( void ) const;
		float	toFloat( void ) const;

		Fixed	abs( void ) const;
		static Fixed&	min( Fixed& a, Fixed& b );
		static Fixed&	max( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream&	operator<<( std::ostream &os, const Fixed& fp );

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:50 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/23 23:10:00 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const float	Fixed::_epsilon = 1e-4f;
const int	Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _fixed_point( 0 ) {}

Fixed::Fixed( int n ) : _fixed_point( n << _fractional_bits ) {}

Fixed::Fixed( float f ) : _fixed_point( roundf( f * ( 1 << _fractional_bits ) ) ) {}

Fixed::Fixed( const Fixed& other ) : _fixed_point( other._fixed_point ) {}

Fixed::~Fixed( void ) {}

void	Fixed::setRawBits( int raw ) {
	_fixed_point = raw;
}

int		Fixed::getRawBits( void ) const {
	return ( _fixed_point );
}

Fixed&	Fixed::operator=( const Fixed& other ) {
	if ( this != &other ) {
		_fixed_point = other._fixed_point;
	}
	return ( *this );
}

Fixed& Fixed::operator=( int n ) {
	_fixed_point = n << _fractional_bits;
	return ( *this );
}

Fixed& Fixed::operator=( float f ) {
	_fixed_point = roundf( f * ( 1 << _fractional_bits ) );
	return ( *this );
}

Fixed	Fixed::operator+( const Fixed& other ) const {
	Fixed	res;
	res.setRawBits( _fixed_point + other._fixed_point );
	return ( res );
}

Fixed	Fixed::operator-( const Fixed& other ) const {
	Fixed	res;
	res.setRawBits( _fixed_point - other._fixed_point );
	return ( res );
}

Fixed	Fixed::operator*( const Fixed& other ) const {
	Fixed	res;
	long	temp;

	temp = ( long )_fixed_point * other._fixed_point;
	res._fixed_point = temp >> _fractional_bits;
	return ( res );
}

Fixed	Fixed::operator/( const Fixed& other ) const {
	Fixed	res;
	long	temp;

	if ( other._fixed_point == 0 ) {
		std::cerr << "Undefined Behavior!" << std::endl;
	}
	temp = ( ( long )_fixed_point << _fractional_bits ) / other._fixed_point;
	res._fixed_point = temp;
	return ( res );
}

Fixed	Fixed::operator+( int n ) const {
	return ( *this + Fixed( n ) );
}

Fixed	Fixed::operator-( int n ) const {
	return ( *this - Fixed( n ) );
}

Fixed	Fixed::operator*( int n ) const {
	return ( *this * Fixed( n ) );
}

Fixed	Fixed::operator/( int n ) const {
	return ( *this / Fixed( n ) );
}

Fixed	Fixed::operator+( float f ) const {
	return ( *this + Fixed( f ) );
}

Fixed	Fixed::operator-( float f ) const {
	return ( *this - Fixed( f ) );
}

Fixed	Fixed::operator*( float f ) const {
	return ( *this * Fixed( f ) );
}

Fixed	Fixed::operator/( float f ) const {
	return ( *this / Fixed( f ) );
}

Fixed&	Fixed::operator++( void ) {
	++_fixed_point;
	return ( *this );
}

Fixed&	Fixed::operator--( void ) {
	--_fixed_point;
	return ( *this );
}

Fixed	Fixed::operator++( int ) {
	Fixed	temp( *this );
	_fixed_point++;
	return ( temp );
}

Fixed	Fixed::operator--( int ) {
	Fixed 	temp( *this );
	_fixed_point--;
	return ( temp );
}

bool	Fixed::operator>( const Fixed& other ) const {
	return ( _fixed_point > other._fixed_point );
}

bool	Fixed::operator>=( const Fixed& other ) const {
	return ( _fixed_point >= other._fixed_point );
}

bool	Fixed::operator<( const Fixed& other ) const {
	return ( _fixed_point < other._fixed_point );
}

bool	Fixed::operator<=( const Fixed& other ) const {
	return ( _fixed_point <= other._fixed_point );
}

bool	Fixed::operator==( const Fixed& other ) const {
	return ( std::fabs( toFloat() - other.toFloat() ) < _epsilon );
}

bool	Fixed::operator!=( const Fixed& other ) const {
	return ( !( *this == other ) );
}

bool	Fixed::operator>( int n ) const {
	return ( *this > Fixed( n ) );
}

bool	Fixed::operator>=( int n ) const {
	return ( *this >= Fixed( n ) );
}

bool	Fixed::operator<( int n ) const {
	return ( *this < Fixed( n ) );
}

bool	Fixed::operator<=( int n ) const {
	return ( *this <= Fixed( n ) );
}

bool	Fixed::operator==( int n ) const {
	return ( std::fabs( toFloat() - static_cast<float>(n) ) < _epsilon );
}

bool	Fixed::operator!=( int n ) const {
	return ( !( *this == n ) );
}

bool	Fixed::operator>( float f ) const {
	return ( *this > Fixed( f ) );
}

bool	Fixed::operator>=( float f ) const {
	return ( *this >= Fixed( f ) );
}

bool	Fixed::operator<( float f ) const {
	return ( *this < Fixed( f ) );
}

bool	Fixed::operator<=( float f ) const {
	return ( *this <= Fixed( f ) );
}

bool	Fixed::operator==( float f ) const {
	return ( std::fabs( toFloat() - f ) < _epsilon );
}

bool	Fixed::operator!=( float f ) const {
	return ( !( *this == f ) );
}

Fixed	Fixed::abs( void ) const {
	return ( *this < 0 ? *this * -1 : *this );
}

Fixed&	Fixed::min( Fixed& a, Fixed& b ) {
	return ( a < b ? a : b );
}

Fixed&	Fixed::max( Fixed& a, Fixed& b ) {
	return ( a > b ? a : b );
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b ) {
	return ( a < b ? a : b );
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b ) {
	return ( a > b ? a : b );
}

std::ostream&	operator<<( std::ostream& os, const Fixed& fp ) {
	os << fp.toFloat();
	return ( os );
}

int	Fixed::toInt( void ) const {
	return ( _fixed_point >> _fractional_bits );
}

float	Fixed::toFloat( void ) const {
	return ( static_cast<float>( _fixed_point ) / ( 1 << _fractional_bits ) );
}

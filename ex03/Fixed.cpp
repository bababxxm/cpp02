/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:50 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 16:11:07 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const float	Fixed::_epsilon = 1e-4f;
const int	Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _rawBits( 0 ) {}

Fixed::Fixed( int n ) : _rawBits( n << _fractionalBits ) {}

Fixed::Fixed( float f ) : _rawBits( roundf( f * ( 1 << _fractionalBits ) ) ) {}

Fixed::Fixed( const Fixed& other ) : _rawBits( other._rawBits ) {}

Fixed::~Fixed( void ) {}

void	Fixed::setRawBits( int raw ) {
	_rawBits = raw;
}

int		Fixed::getRawBits( void ) const {
	return ( _rawBits );
}

Fixed&	Fixed::operator=( const Fixed& other ) {
	if ( this != &other ) {
		_rawBits = other._rawBits;
	}
	return ( *this );
}

Fixed& Fixed::operator=( int n ) {
	_rawBits = n << _fractionalBits;
	return ( *this );
}

Fixed& Fixed::operator=( float f ) {
	_rawBits = roundf( f * ( 1 << _fractionalBits ) );
	return ( *this );
}

Fixed	Fixed::operator+( const Fixed& other ) const {
	Fixed	res;
	res.setRawBits( _rawBits + other._rawBits );
	return ( res );
}

Fixed	Fixed::operator-( const Fixed& other ) const {
	Fixed	res;
	res.setRawBits( _rawBits - other._rawBits );
	return ( res );
}

Fixed	Fixed::operator*( const Fixed& other ) const {
	Fixed	res;
	long	temp;

	temp = ( long )_rawBits * other._rawBits;
	res._rawBits = temp >> _fractionalBits;
	return ( res );
}

Fixed	Fixed::operator/( const Fixed& other ) const {
	Fixed	res;
	long	temp;

	if ( other._rawBits == 0 ) {
		std::cerr << "Undefined Behavior!" << std::endl;
	}
	temp = ( ( long )_rawBits << _fractionalBits ) / other._rawBits;
	res._rawBits = temp;
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
	++_rawBits;
	return ( *this );
}

Fixed&	Fixed::operator--( void ) {
	--_rawBits;
	return ( *this );
}

Fixed	Fixed::operator++( int ) {
	Fixed	temp( *this );
	_rawBits++;
	return ( temp );
}

Fixed	Fixed::operator--( int ) {
	Fixed 	temp( *this );
	_rawBits--;
	return ( temp );
}

bool	Fixed::operator>( const Fixed& other ) const {
	return ( _rawBits > other._rawBits );
}

bool	Fixed::operator>=( const Fixed& other ) const {
	return ( _rawBits >= other._rawBits );
}

bool	Fixed::operator<( const Fixed& other ) const {
	return ( _rawBits < other._rawBits );
}

bool	Fixed::operator<=( const Fixed& other ) const {
	return ( _rawBits <= other._rawBits );
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
	return ( _rawBits >> _fractionalBits );
}

float	Fixed::toFloat( void ) const {
	return ( static_cast<float>( _rawBits ) / ( 1 << _fractionalBits ) );
}

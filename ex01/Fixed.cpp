/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:50 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 15:59:12 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _rawBits( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int raw ) : _rawBits ( raw << _fractionalBits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float raw ) : _rawBits( static_cast<int>( roundf( raw * ( 1 << _fractionalBits ) ) ) ) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other ) : _rawBits( other._rawBits ) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int raw ) {
	_rawBits = raw;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl; 
	return ( _rawBits );
}

Fixed&	Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &other ) {
		_rawBits = other._rawBits;
	}
	return ( *this );
}

std::ostream&	operator<<( std::ostream &os, const Fixed& fixed ) {
	os << fixed.toFloat();
	return ( os );
}

int	Fixed::toInt( void ) const {
	return ( _rawBits >> _fractionalBits );
}

float	Fixed::toFloat( void ) const
{
	return ( static_cast<float>( _rawBits ) / ( 1 << _fractionalBits ) );
}

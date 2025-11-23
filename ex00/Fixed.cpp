/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:50 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/23 23:06:29 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _fixed_point( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other ) : _fixed_point( other._fixed_point ) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl; 
	return ( _fixed_point );
}

Fixed&	Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &other ) {
		_fixed_point = other._fixed_point;
	}
	return ( *this );
}

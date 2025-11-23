/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:16:34 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/23 22:55:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x( Fixed( 0 ) ), _y( Fixed( 0 ) ) {}

Point::Point( float x, float y ) : _x( Fixed( x ) ), _y( Fixed( y ) ) {}

Point::Point( const Point& other ) {
	if ( this != &other ) {
		_x = other._x;
		_y = other._y;
	}
}

Point::~Point( void ) {}

Fixed	Point::getX( void ) const { return ( _x ); }
Fixed	Point::getY( void ) const { return ( _y ); }

Point&	Point::operator=( const Point& other ) {
	if ( this != &other ) {
		_x = other._x;
		_y = other._y;
	}
	return ( *this );
}

Point	Point::operator+( const Point& other ) {
	Point	res;

	res._x = _x + other._x;
	res._y = _y + other._y;
	return ( res );
}

Point	Point::operator-( const Point& other ) {
	Point	res;

	res._x = _x - other._x;
	res._y = _y - other._y;
	return ( res );
}

Point	Point::operator*( const Point& other ) {
	Point	res;

	res._x = _x * other._x;
	res._y = _y * other._y;
	return ( res );
}

Point	Point::operator/( const Point& other ) {
	Point	res;

	if ( other._x == 0 || other._y == 0 ) {
		std::cerr << "Undefined Behavior!" << std::endl;
		return ( Point( 0, 0 ) );
	}
	res._x = _x / other._x;
	res._y = _y / other._y;
	return ( res );
}

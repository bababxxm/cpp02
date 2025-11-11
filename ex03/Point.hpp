/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:16:13 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/10 17:17:07 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{

	private:

		Fixed	_x, _y;

	public:

		Point( void );
		Point( const float x, const float y );
		Point( const Point& other );
		~Point( void );

		Point&	operator=( const Point& other );
		Point	operator+( const Point& other );
		Point	operator-( const Point& other );
		Point	operator*( const Point& other );
		Point	operator/( const Point& other );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
		
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:35:45 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 16:11:44 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	triangleArea( Point const a, Point const b, Point const c ) {
	Fixed	area;
	Fixed	x1 = a.getX(), x2 = b.getX(), x3 = c.getX();
	Fixed	y1 = a.getY(), y2 = b.getY(), y3 = c.getY();

	area = ( x1 * ( y2 - y3 ) + x2 * ( y3 - y1 ) + x3 * ( y1 - y2 ) ) / 2;
	return ( area.abs() );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	ABC = triangleArea( a, b, c );
	Fixed	PAB = triangleArea( point, a, b );
	Fixed	PBC = triangleArea( point, b, c );
	Fixed	PCA = triangleArea( point, c, a );

	if ( PAB == 0 || PBC == 0 || PCA == 0 ) {
		return ( false );
	}
	return ( ABC == PAB + PBC + PCA );
}

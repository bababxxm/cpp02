/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:54 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/23 23:13:06 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int main( void )
{	
	Point	a(5, 5), b(3, 3), c(7, 3);
	Point	inside(5, 4), edge(4, 4), vertex(5, 5), outside(2, 6);

    std::cout << "Inside: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
    std::cout << "Edge: " << (bsp(a, b, c, edge) ? "True" : "False") << std::endl;
    std::cout << "Vertex: " << (bsp(a, b, c, vertex) ? "True" : "False") << std::endl;
    std::cout << "Outside: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;
	return (0);
}

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
	
	public:

		Fixed( void );
		Fixed( int raw );
		Fixed( float raw );
		Fixed( const Fixed& other );
		~Fixed( void );

		void	setRawBits( int raw );
		int		getRawBits( void ) const;
		Fixed&	operator=( const Fixed& other );
		int 	toInt( void ) const;
		float	toFloat( void ) const;
		
};

std::ostream&	operator<<( std::ostream &os, const Fixed& other );

#endif

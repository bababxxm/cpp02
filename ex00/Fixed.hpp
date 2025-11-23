/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:13:52 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/23 22:29:41 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	private:

		int					_fixed_point;
		static const int	_fractional_bits;
	
	public:

		Fixed( void );
		Fixed( const Fixed& other );
		~Fixed( void );

		int		getRawBits( void ) const;
		Fixed&	operator=( const Fixed& other );

};

#endif

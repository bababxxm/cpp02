# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 19:13:56 by sklaokli          #+#    #+#              #
#    Updated: 2025/11/23 22:12:08 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	a.out

SRC		:=	main.cpp \
			Fixed.cpp \
			Point.cpp \
			bsp.cpp

OBJ		:=	$(SRC:%.cpp=%.o)

CPP		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -pedantic

RM		:=	rm -f

all:	$(NAME)

%.o:	%.cpp
		$(CPP) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJ) Makefile
			$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:		Makefile
			$(RM) $(OBJ)

fclean:		clean Makefile
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

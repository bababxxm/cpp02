# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 19:13:56 by sklaokli          #+#    #+#              #
#    Updated: 2025/11/10 15:11:56 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	a.out

SRCS	:=	main.cpp Fixed.cpp
OBJS	:=	$(SRCS:%.cpp=%.o)

CPP		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -pedantic

RM		:=	rm -f

all:	$(NAME)

%.o:	%.cpp
		$(CPP) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) Makefile
			$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:		Makefile
			$(RM) $(OBJS)

fclean:		clean Makefile
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

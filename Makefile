# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 18:39:10 by sbouheni          #+#    #+#              #
#    Updated: 2024/04/30 00:41:14 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	convert

CXX						=	c++
CXXFLAGS				=	-Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address

SRCS					=	source/main.cpp										\
							class/ScalarConverter/ScalarConverter.cpp			\

OBJS					=	$(SRCS:.cpp=.o)

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean					:
							rm -rf $(OBJS)

fclean					:	clean
							rm -rf $(NAME)

re						:	fclean all

.PHONY					:	all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luis <luis@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 15:54:27 by luis              #+#    #+#              #
#    Updated: 2025/04/09 15:54:47 by luis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
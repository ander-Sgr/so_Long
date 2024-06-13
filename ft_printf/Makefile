# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 20:24:11 by aestrell          #+#    #+#              #
#    Updated: 2024/06/13 22:49:14 by aestrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ../libft
SRCS = ft_printf.c \
       ft_put_char.c \
       ft_put_hex.c \
       ft_put_integer.c \
       ft_put_pointer.c \
       ft_put_string.c \
       ft_put_unsigned.c \
       ft_convert_hex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): makelibs $(OBJS)
	@ar -r $(NAME) $(OBJS)

makelibs:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean
	
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	
re: fclean all

.PHONY: all clean fclean re
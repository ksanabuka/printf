# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obuksha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 08:51:16 by obuksha           #+#    #+#              #
#    Updated: 2019/06/20 08:51:21 by obuksha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY:		$(NAME) all clean fclean re
NAME	:=	libftprintf.a
SOURCES	:=	char_print_type_info.c double_print_type_info.c int_print_type_info.c \
			parser.c print_type_info.c string_print_type_info.c uint_print_type_info.c \
			helpers/ft_bzero.c helpers/ft_countwords.c \
			helpers/ft_isdigit.c helpers/ft_iswhitespace.c \
			helpers/ft_memalloc.c \
			helpers/ft_memdel.c helpers/ft_memset.c \
			helpers/ft_putchar.c helpers/ft_putchar_fd.c \
			helpers/ft_putstr.c helpers/ft_putstr_fd.c helpers/ft_strcat.c \
			helpers/ft_strcmp.c \
			helpers/ft_strcpy.c helpers/ft_strdel.c helpers/ft_strdup.c \
			helpers/ft_strjoin.c helpers/ft_strlen.c \
			helpers/ft_strncmp.c helpers/ft_strncpy.c \
			helpers/ft_strnew.c \
			helpers/ft_strsub.c

OBJECTS	:=	$(SOURCES:.c=.o)
OBJECTS	:=	$(subst helpers/,,$(OBJECTS))
all:		$(NAME)
$(NAME):
			gcc -Wall -Wextra -Werror -I. -I./helpers -c $(SOURCES)
			ar rcs $(NAME) $(OBJECTS)
clean:
			rm -f $(OBJECTS)
fclean:		clean
			rm -f $(NAME)
re: 		fclean all
reclean:	re; make clean

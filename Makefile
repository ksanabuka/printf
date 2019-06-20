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
			helpers/ft_atoi.c helpers/ft_bzero.c helpers/ft_countwords.c \
			helpers/ft_isalnum.c helpers/ft_isalpha.c helpers/ft_isascii.c \
			helpers/ft_isdigit.c helpers/ft_isprint.c helpers/ft_iswhitespace.c \
			helpers/ft_itoa.c helpers/ft_lstadd.c helpers/ft_lstdel.c \
			helpers/ft_lstdelone.c helpers/ft_lstiter.c helpers/ft_lstmap.c \
			helpers/ft_lstnew.c helpers/ft_memalloc.c helpers/ft_memccpy.c \
			helpers/ft_memchr.c helpers/ft_memcmp.c helpers/ft_memcpy.c \
			helpers/ft_memdel.c helpers/ft_memmove.c helpers/ft_memset.c \
			helpers/ft_putchar.c helpers/ft_putchar_fd.c helpers/ft_putendl.c \
			helpers/ft_putendl_fd.c helpers/ft_putnbr.c helpers/ft_putnbr_fd.c \
			helpers/ft_putstr.c helpers/ft_putstr_fd.c helpers/ft_strcat.c \
			helpers/ft_strchr.c helpers/ft_strclr.c helpers/ft_strcmp.c \
			helpers/ft_strcpy.c helpers/ft_strdel.c helpers/ft_strdup.c \
			helpers/ft_strequ.c helpers/ft_striter.c helpers/ft_striteri.c \
			helpers/ft_strjoin.c helpers/ft_strlcat.c helpers/ft_strlen.c \
			helpers/ft_strmap.c helpers/ft_strmapi.c helpers/ft_strncat.c \
			helpers/ft_strncmp.c helpers/ft_strncpy.c helpers/ft_strnequ.c \
			helpers/ft_strnew.c helpers/ft_strnstr.c helpers/ft_strrchr.c \
			helpers/ft_strsplit.c helpers/ft_strstr.c helpers/ft_strsub.c \
			helpers/ft_strtrim.c helpers/ft_tolower.c helpers/ft_toupper.c 
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 09:48:30 by sescobar          #+#    #+#              #
#    Updated: 2020/10/22 10:53:31 by sescobar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft

LNAME = libftprintf.a

SOURCE = ft_printf.c \
		 ft_checkflags.c \
		 ft_printint.c \
		 ft_printuint.c \
		 ft_printsymbol.c \
		 ft_printstring.c \
		 ft_spaces.c \
		 ft_printword.c \
		 ft_printchar.c \
		 ft_printhex.c \
		 ft_printpointer.c \
		 tools.c \
		 hex_tools.c

OBJFOLDER = src/lib/

LIBSOURCE = src/lib/ft_atoi.c \
			src/lib/ft_isalpha.c \
			src/lib/ft_itoa.c \
			src/lib/ft_memcpy.c \
			src/lib/ft_putendl_fd.c \
			src/lib/ft_strchr.c \
			src/lib/ft_strlcat.c \
			src/lib/ft_strncmp.c \
			src/lib/ft_substr.c \
			src/lib/ft_bzero.c \
			src/lib/ft_isascii.c \
			src/lib/ft_memccpy.c \
			src/lib/ft_memmove.c \
			src/lib/ft_putnbr_fd.c \
			src/lib/ft_strcmp.c \
			src/lib/ft_strlcpy.c \
			src/lib/ft_strnstr.c \
			src/lib/ft_tolower.c \
			src/lib/ft_calloc.c \
			src/lib/ft_isdigit.c \
			src/lib/ft_memchr.c \
			src/lib/ft_memset.c\
			src/lib/ft_putstr_fd.c \
			src/lib/ft_strdup.c \
			src/lib/ft_strlen.c \
			src/lib/ft_strrchr.c \
			src/lib/ft_toupper.c \
			src/lib/ft_isalnum.c \
			src/lib/ft_isprint.c \
			src/lib/ft_memcmp.c \
			src/lib/ft_putchar_fd.c \
			src/lib/ft_split.c \
			src/lib/ft_strjoin.c \
			src/lib/ft_strmapi.c \
			src/lib/ft_strtrim.c \

OBJ = $(SOURCE:.c=.o)

LIBOBJ = $(LIBSOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -c

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(LFLAGS) $(LIBSOURCE)
	@mv -f *.o src/lib
	@gcc $(CFLAGS) $(LFLAGS) $(SOURCE)
	@ar rc $(LNAME) $(OBJ) $(LIBOBJ)
	@ranlib $(LNAME)
	@echo "'$(NAME)' Compilada correctamente"

clean:
	@rm -f $(LIBOBJ) $(LBONUSSRC) $(OBJ) $(LIBOBJ) src/lib/*.o
	@echo "Borrado completado"

fclean: clean
	@rm -f $(LNAME)
	@echo "'$(LNAME)' Eliminada correctamente"

re: fclean all

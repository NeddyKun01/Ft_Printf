# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/07 09:08:00 by neddykun          #+#    #+#              #
#    Updated: 2026/07/07 09:08:21 by neddykun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PT: Nome da biblioteca estatica que o projeto deve gerar.
# EN: Name of the static library that the project must generate.
NAME=libft.a

# PT: Compilador, flags obrigatorias e ferramenta para criar a biblioteca.
# EN: Compiler, required flags and tool used to create the library.
CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs
RM=rm -f

# PT: O primeiro alvo executado quando escreves apenas "make".
# EN: The first target executed when you type only "make".
.DEFAULT_GOAL := all

# PT: Part 1 - Funcoes da libc reimplementadas.
# EN: Part 1 - Reimplemented libc functions.
PART1_SRCS=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c

# PT: Part 2 - Funcoes adicionais pedidas pelo subject.
# EN: Part 2 - Additional functions required by the subject.
PART2_SRCS=	ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

# PT: Part 3 - Funcoes obrigatorias para listas ligadas.
# EN: Part 3 - Mandatory linked-list functions.
PART3_SRCS=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

# PT: Todos os ficheiros fonte que entram na biblioteca.
# EN: Every source file that goes into the library.
SRCS=$(PART1_SRCS) $(PART2_SRCS) $(PART3_SRCS)

# PT: Objetos gerados a partir dos ficheiros .c.
# EN: Object files generated from the .c files.
OBJS=$(SRCS:.c=.o)

# PT: Constroi a biblioteca.
# EN: Builds the library.
all: $(NAME)

# PT: Cria ou atualiza a biblioteca estatica libft.a.
# EN: Creates or updates the static library libft.a.
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# PT: Regra generica: transforma cada .c no seu .o.
# EN: Generic rule: turns each .c file into its .o file.
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# PT: Remove apenas os ficheiros objeto.
# EN: Removes only object files.
clean:
	$(RM) $(OBJS)

# PT: Remove os objetos e a biblioteca final.
# EN: Removes object files and the final library.
fclean: clean
	$(RM) $(NAME)

# PT: Limpa tudo e constroi novamente.
# EN: Cleans everything and builds again.
re: fclean all

# PT: Alvos que sao comandos, nao ficheiros reais.
# EN: Targets that are commands, not real files.
.PHONY: all clean fclean re

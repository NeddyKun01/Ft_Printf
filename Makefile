# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/14 07:44:06 by neddykun          #+#    #+#              #
#    Updated: 2026/07/14 07:44:07 by neddykun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
CP = cp
RM = rm -f

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
MANDATORY = .mandatory
BONUS = .bonus

SRCS = ft_printf.c ft_print_text.c ft_print_numbers.c ft_print_hex.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_printf_bonus.c ft_utils_bonus.c ft_base_utils_bonus.c \
	ft_parse_bonus.c ft_render_base_bonus.c ft_render_text_bonus.c \
	ft_render_num_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY)

$(MANDATORY): $(LIBFT) $(OBJS)
	$(CP) $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	touch $(MANDATORY)
	$(RM) $(BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c ft_printf_bonus.h $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	$(CP) $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	touch $(BONUS)
	$(RM) $(MANDATORY)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(MANDATORY) $(BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:13:27 by pvong             #+#    #+#              #
#    Updated: 2023/03/10 17:30:20 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ../org_libft/libft.a
LIBFT_DIR	= ../org_libft

SOURCES	=	ft_printf \
			ft_printhex \
			ft_printnbr \
			ft_printptr

SRC		=	$(addsuffix .c, $(SOURCES))

# OBJS

OBJS_DIR		=	objs
OBJS			=	$(addprefix ./$(OBJS_DIR)/, $(addsuffix .o, $(SOURCES)))

# COMPILATION

INC				=	-I ./includes -I $(LIBFT_DIR)/includes
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo -n .

$(NAME):	$(LIBFT) $(OBJS)
			@cp ../org_libft/libft.a .
			@mv libft.a $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo "$(BLUE)\nCreated $@$(END)"

$(LIBFT):
			@make -C $(LIBFT_DIR)

clean:
			@make -C $(LIBFT_DIR) clean
			@rm -rf $(OBJS_DIR)

fclean:		clean
			@make -C $(LIBFT_DIR) fclean
			@rm -f $(NAME)

re:			fclean all

.PHONY: all fclean clean re
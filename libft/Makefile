# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 14:49:58 by pvong             #+#    #+#              #
#    Updated: 2023/03/10 17:16:05 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT = ./org_libft/libft.a
LIBFT_DIR = ./org_libft
FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_DIR = ./ft_printf
GNL = ./gnl/libgnl.a
GNL_DIR = ./gnl

# Colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
END				=	\033[0m

all: $(NAME)

$(NAME): $(FT_PRINTF) $(GNL)
		@cp $(GNL) .
		@mv libgnl.a $(NAME)
		@ar rcs $(NAME) $(FT_PRINTF)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(GNL):
	@make -C $(GNL_DIR)

clean:
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(GNL_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

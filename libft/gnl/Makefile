# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:05:53 by pvong             #+#    #+#              #
#    Updated: 2023/03/10 17:23:55 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

# Colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
END				=	\033[0m

SOURCES		=	get_next_line \
				get_next_line_utils

SOURCESB	=	get_next_line_bonus \
				get_next_line_utils_bonus

SRC			=	$(addsuffix .c, $(SOURCES))
SRCB		=	$(addsuffix .c, $(SOURCESB))

# OBJS

OBJS_DIR		=	objs
OBJSB_DIR		=	objsb
OBJS			=	$(addprefix ./$(OBJS_DIR)/, $(addsuffix .o, $(SOURCES)))
OBJSB			=	$(addprefix ./$(OBJSB_DIR)/, $(addsuffix .o, $(SOURCESB)))

# COMPILATION

INC				=	-I ./includes
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
BONUS_CACHE		=	.bonus

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo -n .

$(OBJSB_DIR)/%.o: $(SRCB)
	@mkdir -p $(OBJSB_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo -n .

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@echo "$(BLUE)\nCreated $@$(END)"

bonus:	$(BONUS_CACHE)

$(BONUS_CACHE):		$(OBJSB)
			@ar rcs $(NAME) $(OBJSB)
			@echo cache > $(BONUS_CACHE)
			@echo "$(BLUE)\nCreated $(NAME)$(END)"

clean:
			@rm -rf $(OBJS_DIR)
			@rm -rf $(OBJSB_DIR)
			@rm -f $(BONUS_CACHE)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: all fclean clean re
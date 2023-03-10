# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 15:15:30 by pvong             #+#    #+#              #
#    Updated: 2023/03/10 17:23:05 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
END				=	\033[0m

# LIBFT

ISALNUM_DIR = ft_isalnum
LIST_DIR = ft_list
MEM_DIR =  ft_mem
PUT_DIR = ft_put
STR_DIR = ft_str

ISALNUM_SOURCES		=	ft_isalnum \
						ft_isalpha \
						ft_isascii \
						ft_isdigit \
						ft_isprint

ISALNUM_PREF		= $(addprefix ./$(ISALNUM_DIR)/, $(ISALNUM_SOURCES))
ISALNUM_SRC			= $(addsuffix .c, $(ISALNUM_PREF))

LIST_SOURCES		=	ft_lstadd_back \
						ft_lstadd_front \
						ft_lstdelone \
						ft_lstlast \
						ft_lstnew \
						ft_lstsize

LIST_PREF			= $(addprefix ./$(LIST_DIR)/, $(LIST_SOURCES))
LIST_SRC			= $(addsuffix .c, $(LIST_PREF))

MEM_SOURCES			=	ft_bzero \
						ft_calloc \
						ft_memchr \
						ft_memcmp \
						ft_memcpy \
						ft_memmove \
						ft_memset

MEM_PREF			= $(addprefix ./$(MEM_DIR)/, $(MEM_SOURCES))
MEM_SRC				= $(addsuffix .c, $(MEM_PREF))

PUT_SOURCES			=	ft_putchar_fd \
						ft_putendl_fd \
						ft_putnbr_fd \
						ft_putstr_fd

PUT_PREF			= $(addprefix ./$(PUT_DIR)/, $(PUT_SOURCES))
PUT_SRC				= $(addsuffix .c, $(PUT_PREF))

STR_SOURCES			=	ft_strchr \
						ft_strdup \
						ft_striteri \
						ft_strjoin \
						ft_strjoin \
						ft_strlcat \
						ft_strlcpy \
						ft_strlen \
						ft_strmapi \
						ft_strncmp \
						ft_strnstr \
						ft_strrchr \
						ft_strtrim \
						ft_substr \
						ft_tolower \
						ft_toupper \

STR_PREF			=	$(addprefix ./$(STR_DIR)/, $(STR_SOURCES))
STR_SRC				=	$(addsuffix .c, $(STR_PREF))

LIBFT_OTHERS		=	ft_atoi \
						ft_itoa \
						ft_split

LIBFT_OTHERS_SRC	=	$(addsuffix .c, $(LIBFT_OTHERS))

SOURCES		=	$(ISALNUM_SOURCES) \
						$(LIST_SOURCES) \
						$(MEM_SOURCES) \
						$(PUT_SOURCES) \
						$(STR_SOURCES) \
						$(LIBFT_OTHERS)


SRC =	$(ISALNUM_SRC) \
			$(LIST_SRC) \
			$(MEM_SRC) \
			$(PUT_SRC) \
			$(STR_SRC) \
			$(LIBFT_OTHERS_SRC)

# OBJS

OBJS_DIR		=	objs
OBJS			=	$(addprefix ./$(OBJS_DIR)/, $(addsuffix .o, $(SOURCES)))

# COMPILATION

INC				=	-I ./includes
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

# all: ; $(info $$var is [${SRC}])

$(OBJS_DIR)/%.o: $(SRC)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo -n .

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@echo "$(BLUE)\nCreated $@$(END)"

git:
	git add .
	git commit -am "update"
	git push

clean:
			@rm -rf $(OBJS_DIR)
			@rm -rf $(OBJSB_DIR)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: all fclean clean re

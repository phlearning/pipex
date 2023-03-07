NAME 			= pipex

# Colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
END				=	\033[0m

# Ft_printf
FT_PRINTF_DIR	= ft_printf
FT_PRINTFA		= $(addprefix ./$(FT_PRINTF_DIR)/, libftprintf.a)
FT_PRINTF_INC	= -I ./$(FT_PRINTF_DIR)/includes
FT_PRINTF_LNK	= -L $(FT_PRINTF_DIR) -lftprintf

# Libft

LIBFT_DIR		= libft
LIBFTA			= $(addprefix ./$(LIBFT_DIR)/, libft.a)
LIB_INC			= -I $(LIBFT_DIR)
LIB_LNK			= -L $(LIBFT_DIR) -lft


# SRCS

SRC_DIR			= src

SOURCES			= 	main.c \
					parsing.c \
					process.c \
					utils.c

SRCB_DIR		=	src_bonus

SOURCESB		=	main_bonus.c \
					parsing_bonus.c \
					process_bonus.c \
					utils_bonus.c

SRC = $(addprefix $(SRC_DIR)/,$(SOURCES))
SRCB = $(addprefix $(SRCB_DIR)/,$(SOURCESB))

# OBJS

OBJS_DIR 		= objs
TMP				= $(OBJS_DIR)
OBJS 			= $(addprefix ./$(OBJS_DIR)/,$(SOURCES:.c=.o))
OBJS_DIRFS 		= objsfs
TMPFS			= $(OBJS_DIRFS)
OBJSFS 			= $(addprefix ./$(OBJS_DIRFS)/,$(SOURCES:.c=.o))

OBJSB_DIR		= objs_bonus
TMPB			= $(OBJSB_DIR)
OBJSB			= $(addprefix ./$(OBJSB_DIR)/,$(SOURCESB:.c=.o))

# Compiling

CC				= gcc

CFLAGS 			= -Wall -Werror -Wextra

INCLUDE 		= -I includes

DEBUG			= debug

all:	$(NAME)

$(TMP):
	@mkdir -p $(OBJS_DIR)

$(TMPFS):
	@mkdir -p $(OBJS_DIRFS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(LIB_INC) $(FT_PRINTF_INC) $(INCLUDE) -c $< -o $@
	@echo "Compiling $@..."

$(NAME): $(TMP) $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft compiled $(END)"
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(GREEN) Ft_printf compiled $(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_LNK) $(FT_PRINTF_LNK) -o $(NAME)
	@echo "$(GREEN) $(NAME) Compiled $(END)"

$(TMPB):
	@mkdir -p $(OBJSB_DIR)

$(OBJSB_DIR)/%.o: $(SRCB_DIR)/%.c
	@mkdir -p $(OBJSB_DIR)
	@$(CC) $(CFLAGS) $(LIB_INC) $(FT_PRINTF_INC) $(INCLUDE) -c $< -o $@
	@echo "Compiling $@..."

bonus: $(TMPB) $(OBJSB)
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft compiled $(END)"
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(GREEN) Ft_printf compiled $(END)"
	@$(CC) $(CFLAGS) $(OBJSB) $(LIB_LNK) $(FT_PRINTF_LNK) -o $(NAME)
	@echo "$(GREEN) $(NAME) Compiled $(END)"

$(OBJS_DIRFS)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIRFS)
	@$(CC) -g3 -fsanitize=address $(CFLAGS) $(LIB_INC) $(FT_PRINTF_INC) $(INCLUDE) -c $< -o $@
	@echo "Compiling $@..."

fsanitize: $(TMPFS) $(OBJSFS)
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft compiled $(END)"
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(BLUE) Ft_printf compiled $(END)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(OBJSFS) $(LIB_LNK) $(FT_PRINTF_LNK) -o $(DEBUG)
	@echo "$(BLUE) $(DEBUG) Compiled $(END)"

checkfunction:
	$(shell nm -A ./objs/*) > checkfunction.txt

git:
	git add .
	git commit -am "update"
	git push

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJSB_DIR)
	@rm -rf $(OBJS_DIRFS)
	@rm -rf checkfunction.txt
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(FT_PRINTF_DIR) clean
	@echo "$(BLUE)$(NAME) Cleaning Done$(END)"

fclean: clean
	@rm -rf $(NAME)
	@rm -f debug
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(FT_PRINTF_DIR) fclean
	@echo "$(BLUE)$(NAME) Fcleaning Done$(END)"

re: fclean all

.PHONY: all fclean clean re temp
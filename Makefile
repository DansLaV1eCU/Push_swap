#Program name
NAME	= push_swap

# Bonus name
BNAME = bonus

# Compiler
CC		= cc
CFLAGS	= -Werror -Wextra -Wall

# Libft
LIBFT_PATH	= includes/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./includes/libft/\

# Sources
SRC_PATH	=	src/main/
SRC			=	add_free_stack.c \
				find_cheapest.c \
				move_cheapest.c \
				operations1.c \
				operations2.c \
				push_swap.c \
				sort_utils.c \
				split.c \
				utils.c 
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
BSRCS		= $(addprefix $(BSRC_PATH), $(BSRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
BOBJ		= $(BSRC:.c=.o)
BOBJS		= $(addprefix $(OBJ_PATH), $(BOBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@echo "Making libft..."
	make -sC $(LIBFT_PATH)

$(NAME): $(OBJS) | $(LIBFT)
	@echo "Compiling push_swap..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC)
	@echo "push_swap is ready."

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing push_swap..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean bonus
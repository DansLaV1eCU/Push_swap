#Program name
NAME	= push_swap

# Bonus name
BNAME = bonus

# Compiler
CC		= cc
CFLAGS	= -Werror -Wextra -Wall -std=c99

# Libft
LIBFT_PATH	= ~/libft/
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
				utils.c \
				split.c

# Bonus sources
BSRC_PATH = src/bonus/
BSRC = bonus.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))
BSRCS		= $(addprefix $(BSRC_PATH), $(BSRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
BOBJ		= $(BSRC:.c=.o)
BOBJS		= $(addprefix $(OBJ_PATH), $(BOBJ))

all: $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC)
	@echo "push_swap is ready."

bonus: all $(BOBJS)
		

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
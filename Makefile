# Project Configuration
NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_DIR		= minilibx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Source files
SRCS		= ft_atof.c \
			  ft_atoi.c \
			  main.c \
			  parsing.c \
			  ft_split.c \
			  get_next_line.c \
			  ft_strlen.c \
			  ft_putstr_fd.c \
			  ft_strcmp.c \
			  ft_substr.c \
			  ft_strdup.c \
			  ft_memset.c

# Object files
OBJS		= $(SRCS:.c=.o)

# Header files
INCLUDES	= -I. -I$(MLX_DIR)

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
NC			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(MLX_FLAGS)
	@echo "$(GREEN)Successfully compiled $(NAME)$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

clean:
	@rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@echo "$(RED)Removed object files$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re
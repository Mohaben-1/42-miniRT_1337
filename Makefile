# Project Configuration
NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O2 -DGL_SILENCE_DEPRECATION
MLX_DIR		= minilibx
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Source files
SRCS		= utils/ft_atof.c \
			  utils/ft_atoi.c \
			  main.c \
			  parsing.c \
			  utils/ft_split.c \
			  utils/get_next_line.c \
			  utils/ft_strlen.c \
			  utils/ft_putstr_fd.c \
			  utils/ft_strcmp.c \
			  utils/ft_substr.c \
			  utils/ft_strdup.c \
			  utils/ft_memset.c \
			  print_scene.c \
			  rendering.c \
			  vec_ops.c 

# Object files
OBJS		= $(SRCS:.c=.o)

# Header files
INCLUDES	= -I. -I$(MLX_DIR)

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
NC			= \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(MLX_FLAGS)
	@echo "$(GREEN)Successfully compiled $(NAME)$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)Removed object files$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re
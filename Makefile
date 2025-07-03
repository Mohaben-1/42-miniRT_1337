# Project Configuration
NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_DIR		= mandatory/mlx
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Source files
SRCS		= mandatory/main.c \
			mandatory/check/check_ambient.c mandatory/check/check_arg.c mandatory/check/check_camera.c mandatory/check/check_cylinder.c mandatory/check/check_light.c mandatory/check/check_plane.c mandatory/check/check_sphere.c mandatory/check/check_utils.c \
			mandatory/parsing/parse_elements.c mandatory/parsing/parse_shapes.c mandatory/parsing/init_rt.c mandatory/parsing/create_scene.c \
			mandatory/math/vec_ops.c \
			mandatory/mlx_utils/ft_mlx_events.c mandatory/mlx_utils/mlx_init.c \
			mandatory/utils/free.c mandatory/utils/ft_atoi.c mandatory/utils/ft_count_args.c mandatory/utils/ft_isspace.c mandatory/utils/ft_putnbr_fd.c mandatory/utils/ft_split.c  mandatory/utils/ft_strdup.c mandatory/utils/ft_strncmp.c mandatory/utils/get_next_line.c mandatory/utils/object_list.c \
			mandatory/utils/ft_atof.c mandatory/utils/ft_calloc.c mandatory/utils/ft_empty_str.c mandatory/utils/ft_memset.c mandatory/utils/ft_putstr_fd.c mandatory/utils/ft_strcmp.c mandatory/utils/ft_strlen.c mandatory/utils/ft_substr.c mandatory/utils/ft_isalnum.c

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
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

SRCS_BNS =  bonus/main_bonus.c \
			bonus/check_bonus/check_ambient_bonus.c bonus/check_bonus/check_arg_bonus.c bonus/check_bonus/check_camera_bonus.c bonus/check_bonus/check_cylinder_bonus.c bonus/check_bonus/check_light_bonus.c bonus/check_bonus/check_plane_bonus.c bonus/check_bonus/check_sphere_bonus.c bonus/check_bonus/check_utils_bonus.c bonus/check_bonus/check_cone_bonus.c \
			bonus/parsing_bonus/parse_elements_bonus.c bonus/parsing_bonus/parse_shapes_bonus.c bonus/parsing_bonus/init_rt_bonus.c bonus/parsing_bonus/create_scene_bonus.c \
			bonus/math_bonus/vec_ops_bonus.c \
			bonus/mlx_utils_bonus/ft_mlx_events_bonus.c bonus/mlx_utils_bonus/mlx_init_bonus.c \
			bonus/utils_bonus/free_bonus.c bonus/utils_bonus/ft_atoi_bonus.c bonus/utils_bonus/ft_count_args_bonus.c bonus/utils_bonus/ft_isspace_bonus.c bonus/utils_bonus/ft_putnbr_fd_bonus.c bonus/utils_bonus/ft_split_bonus.c  bonus/utils_bonus/ft_strdup_bonus.c bonus/utils_bonus/ft_strncmp_bonus.c bonus/utils_bonus/get_next_line_bonus.c bonus/utils_bonus/object_list_bonus.c \
			bonus/utils_bonus/ft_atof_bonus.c bonus/utils_bonus/ft_calloc_bonus.c bonus/utils_bonus/ft_empty_str_bonus.c bonus/utils_bonus/ft_memset_bonus.c bonus/utils_bonus/ft_putstr_fd_bonus.c bonus/utils_bonus/ft_strcmp_bonus.c bonus/utils_bonus/ft_strlen_bonus.c bonus/utils_bonus/ft_substr_bonus.c bonus/utils_bonus/ft_isalnum_bonus.c

# Object files
OBJS		= $(SRCS:.c=.o)

OBJS_BNS	= $(SRCS_BNS:.c=.o)

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

bonus: $(OBJS_BNS) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BNS) -o $(NAME) $(MLX_FLAGS)
	@echo "$(GREEN)Successfully compiled $(NAME)$(NC)"

%_bonus.o: %_bonus.c bonus/includes_bonus/minirt_bonus.h bonus/includes_bonus/structs_bonus.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

%.o: %.c mandatory/includes/minirt.h  mandatory/includes/structs.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

clean:
	@rm -f $(OBJS) $(OBJS_BNS)
	@echo "$(RED)Removed object files$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re bonus
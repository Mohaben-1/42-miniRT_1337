# Project Configuration
NAME		= miniRT
NAME_BONUS	= miniRT_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_DIR		= MLX42
MLX_LIB		= $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS	= -L$(MLX_DIR)/build -lmlx42 -L /goinfre/$(USER)/homebrew/opt/glfw/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit

# Mandatory source files
SRCS		= mandatory/main.c \
			mandatory/check/check_ambient.c mandatory/check/check_arg.c mandatory/check/check_camera.c mandatory/check/check_cylinder.c mandatory/check/check_light.c \
			mandatory/check/check_plane.c mandatory/check/check_sphere.c mandatory/check/check_utils.c mandatory/check/check_utils2.c mandatory/check/check_vecs.c \
			mandatory/parsing/parse_elements.c mandatory/parsing/parse_shapes.c mandatory/parsing/init_rt.c mandatory/parsing/create_scene.c \
			mandatory/math/vec_ops.c mandatory/math/vec_ops_2.c mandatory/math/vec_create.c mandatory/math/vec_utils.c \
			mandatory/rendring/color_rgb.c mandatory/rendring/cylinder_utils2.c mandatory/rendring/hit_cylinder.c mandatory/rendring/hit_plane.c \
			mandatory/rendring/hit_sphere.c mandatory/rendring/hit_detection.c mandatory/rendring/lighting.c mandatory/rendring/ray_color.c \
			mandatory/rendring/render_scene.c mandatory/rendring/determine_surface_normal.c \
			mandatory/rendring/project_onto_plane.c mandatory/rendring/cylinder_utils.c mandatory/rendring/ray_shadow.c \
			mandatory/mlx_utils/ft_mlx_events.c mandatory/mlx_utils/mlx_init.c mandatory/mlx_utils/mlx_pixel_draw.c \
			mandatory/utils/free.c mandatory/utils/ft_atoi.c mandatory/utils/ft_count_args.c mandatory/utils/ft_isspace.c mandatory/utils/ft_putnbr_fd.c mandatory/utils/ft_split.c mandatory/utils/ft_trim_line.c \
			mandatory/utils/ft_strdup.c mandatory/utils/ft_strncmp.c mandatory/utils/get_next_line.c mandatory/utils/object_list.c mandatory/utils/ft_strjoin.c mandatory/utils/ft_strchr.c \
			mandatory/utils/ft_atof.c mandatory/utils/ft_calloc.c mandatory/utils/ft_empty_str.c mandatory/utils/ft_memset.c mandatory/utils/ft_putstr_fd.c mandatory/utils/ft_strcmp.c mandatory/utils/ft_strlen.c mandatory/utils/ft_substr.c mandatory/utils/ft_isalnum.c

# Bonus source files
SRCS_BNS =  Bonus/main_bonus.c \
			Bonus/check_bonus/check_ambient_bonus.c Bonus/check_bonus/check_arg_bonus.c Bonus/check_bonus/check_camera_bonus.c \
			Bonus/check_bonus/check_cylinder_bonus.c Bonus/check_bonus/check_light_bonus.c Bonus/check_bonus/check_plane_bonus.c \
			Bonus/check_bonus/check_sphere_bonus.c Bonus/check_bonus/check_utils_bonus.c Bonus/check_bonus/check_cone_bonus.c \
			Bonus/check_bonus/check_texture_bonus.c Bonus/check_bonus/check_utils2_bonus.c Bonus/check_bonus/check_vecs_bonus.c \
			Bonus/parsing_bonus/parse_elements_bonus.c Bonus/parsing_bonus/init_rt_bonus.c Bonus/parsing_bonus/create_scene_bonus.c \
			Bonus/parsing_bonus/parse_cylinder_bonus.c Bonus/parsing_bonus/parse_cone_bonus.c Bonus/parsing_bonus/parse_sphere_bonus.c Bonus/parsing_bonus/parse_plane_bonus.c \
			Bonus/math_bonus/vec_ops_bonus.c  Bonus/math_bonus/vec_ops_2_bonus.c Bonus/math_bonus/vec_create_bonus.c Bonus/math_bonus/vec_utils_bonus.c \
			Bonus/mlx_utils_bonus/ft_mlx_events_bonus.c Bonus/mlx_utils_bonus/mlx_init_bonus.c Bonus/mlx_utils_bonus/mlx_pixel_draw_bonus.c \
			Bonus/utils_bonus/free_bonus.c Bonus/utils_bonus/ft_atoi_bonus.c Bonus/utils_bonus/ft_count_args_bonus.c Bonus/utils_bonus/ft_isspace_bonus.c Bonus/utils_bonus/ft_putnbr_fd_bonus.c Bonus/utils_bonus/ft_split_bonus.c  Bonus/utils_bonus/ft_strdup_bonus.c Bonus/utils_bonus/ft_strncmp_bonus.c Bonus/utils_bonus/get_next_line_bonus.c Bonus/utils_bonus/object_list_bonus.c \
			Bonus/utils_bonus/ft_atof_bonus.c Bonus/utils_bonus/ft_calloc_bonus.c Bonus/utils_bonus/ft_empty_str_bonus.c Bonus/utils_bonus/ft_memset_bonus.c Bonus/utils_bonus/ft_putstr_fd_bonus.c Bonus/utils_bonus/ft_strcmp_bonus.c Bonus/utils_bonus/ft_strlen_bonus.c Bonus/utils_bonus/ft_substr_bonus.c Bonus/utils_bonus/ft_isalnum_bonus.c Bonus/utils_bonus/ft_trim_line_bonus.c \
			Bonus/utils_bonus/ft_strjoin_bonus.c Bonus/utils_bonus/ft_strchr_bonus.c Bonus/rendring_bonus/hit_cone_utils_bonus.c Bonus/rendring_bonus/ray_color_utils_bonus.c \
			Bonus/rendring_bonus/color_rgb_bonus.c Bonus/rendring_bonus/cylinder_utils2_bonus.c Bonus/rendring_bonus/hit_cylinder_bonus.c Bonus/rendring_bonus/hit_plane_bonus.c \
			Bonus/rendring_bonus/hit_sphere_bonus.c Bonus/rendring_bonus/hit_detection_bonus.c Bonus/rendring_bonus/lighting_bonus.c Bonus/rendring_bonus/ray_color_bonus.c \
			Bonus/rendring_bonus/bump_map_utils_bonus.c Bonus/rendring_bonus/bump_map_bonus.c Bonus/rendring_bonus/checkerboard_cone_bonus.c Bonus/rendring_bonus/bump_color_bonus.c \
			Bonus/rendring_bonus/render_scene_bonus.c Bonus/rendring_bonus/determine_surface_normal_bonus.c Bonus/rendring_bonus/hit_cone_bonus.c \
			Bonus/rendring_bonus/project_onto_plane_bonus.c Bonus/rendring_bonus/cylinder_utils_bonus.c Bonus/rendring_bonus/ray_shadow_bonus.c Bonus/rendring_bonus/checkerboard_bonus.c \


# Object files
OBJS		= $(SRCS:.c=.o)
OBJS_BNS	= $(SRCS_BNS:.c=.o)

# Header files
INCLUDES	= -I. -I$(MLX_DIR)/include

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
NC			= \033[0m

all: $(NAME)

bonus: $(NAME_BONUS)


$(NAME): $(OBJS) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(MLX_FLAGS)
	@echo "$(GREEN)Successfully compiled $(NAME)$(NC)"

$(NAME_BONUS): $(OBJS_BNS) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BNS) -o $(NAME_BONUS) $(MLX_FLAGS)
	@echo "$(GREEN)Successfully compiled $(NAME_BONUS)$(NC)"


%_bonus.o: %_bonus.c Bonus/includes_bonus/minirt_bonus.h Bonus/includes_bonus/structs_bonus.h Bonus/includes_bonus/errors_bonus.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

%.o: %.c mandatory/includes/minirt.h  mandatory/includes/structs.h mandatory/includes/errors.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

clean:
	@rm -f $(OBJS) $(OBJS_BNS)
	@echo "$(RED)Removed object files$(NC)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)Removed $(NAME) and $(NAME_BONUS)$(NC)"

re: fclean all

.PHONY: all bonus clean fclean re

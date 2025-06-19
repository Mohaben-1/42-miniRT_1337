/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:15:01 by ahouass           #+#    #+#             */
/*   Updated: 2025/06/19 19:43:21 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <math.h>
# include <printf.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
#include <unistd.h>


typedef struct s_vec3
{
	float x;
	float y;
	float z;
}	t_vec3;

typedef struct s_ambient
{
	float	ratio;
	t_vec3	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	orientation;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3			position;
	float			brightness;
	t_vec3			color;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	t_vec3	center;
	float	diameter;
	t_vec3	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	float	diameter;
	float	height;
	t_vec3	color;
}	t_cylinder;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_object_type;

// typedef struct s_material
// {
// 	t_vec3 color;
// }	t_material;

typedef struct s_object {
	t_object_type type;
	// t_material material;
	union {
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	} data;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		*lights;
	t_object	*objects;
	void		*mlx;
	void		*win;
	void		*img;
	bool		has_ambient;
	bool		has_camera;
	bool		has_light;
	int			win_width;
	int			win_height;
}	t_scene;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_scene	*scene;
}	t_mlx;

t_scene	*ft_parse_scene(char *av);
char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char	*str);
char	**ft_split(char const *s, char c);
double	ft_atof(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	ft_free_scene(t_scene *scene);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);


void	print_scene(t_scene *scene);


//mlx
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//vector operations
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_scale(t_vec3 v, double s);
double	vec_dot(t_vec3 a, t_vec3 b);
double	vec_len(t_vec3 v);
t_vec3	vec_normalize(t_vec3 v);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);

void	render_scene(t_mlx *mlx);

#endif
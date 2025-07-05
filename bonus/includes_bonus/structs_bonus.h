/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:41:40 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/05 16:30:08 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCTS_BONUS_H
#define STRUCTS_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
}	t_mlx;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_light
{
	t_vec		position;
	t_color		color;
	double		intensity;
}	t_light;

typedef struct s_variation
{
	double	min;
	double	max;	
}	t_variation;

typedef struct s_camera
{
	double	viewport_height;
	double	viewport_width;
	double	focal_len;
	double	fov;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	lower_left_corner;
	t_vec	view_up; // up vector (view_up)
	t_vec	origin; // camera position (look_from)
	t_vec	target; // what the camera is looking at (look_at)
}	t_camera;

typedef struct s_ambient
{
	t_color	color;
	double	ratio;
}	t_ambient;

typedef struct s_hit_data
{
	t_vec	point;          // Where the ray hit
	t_vec	normal;         // Surface normal at the hit point
	double	t;              // Ray parameter at the hit
	bool	is_front_face;  // True if the hit is on the outside
	int		object_id;      // ID/index of the object hit
	int		skip_id;        // ID of object to skip (e.g., in shadow rays)
}	t_hit_data;

typedef enum e_texture_type
{
	TEX_NONE,
	TEX_CHECKER,
	TEX_BUMP
}	t_texture_type;

typedef struct s_material
{
	t_color			color;
	double			ambient;
	double			diffuse;
	double			specular;
	double			shininess;
	t_texture_type	texture_type;
}	t_material;

typedef struct s_sphere
{
	t_vec		center;
	double		radius;
	int			type;
	t_material	material;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec		axis;
	t_vec		center;
	double		radius;
	double		height;
	t_vec		cap_top;
	t_vec		cap_bottom;
	int			type;
	t_material	material;
}	t_cylinder;

typedef struct s_cone
{
	t_vec		vertex;
	t_vec		axis;
	int			type;
	double		angle;
	double		height;
	t_material	material;
}	t_cone;

typedef struct s_plane
{
	t_vec		normal;
	t_vec		position;
	int			type;
	t_material	material;
}	t_plane;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CONE
}	t_object_type;

typedef struct s_object
{
	union
	{
		t_sphere	*sphere;
		t_cylinder	*cylinder;
		t_plane		*plane;
		t_cone		*cone;
	};
	int				type;
	int				id;
	struct s_object	*next;
}	t_object;

typedef struct s_object_list
{
	t_object	*head;
}	t_object_list;

typedef struct s_light_list
{
	t_light				light;
	struct s_light_list	*next;
}	t_light_list;

typedef struct s_ray
{
	t_vec	origin;
	union
	{
		t_vec	direction;
		t_vec	dir;
	};
}	t_ray;

typedef struct s_hit
{
	union
	{
		void		*object;
		t_sphere	*sphere;
		t_cylinder	*cyl;
		t_plane		*plane;
		t_cone		*cone;
	};
	t_variation		variation;
	t_ray			*ray;
	t_hit_data		*hit_data;
}				t_hit;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	root1;
	double	root2;
}	t_quadratic;

typedef struct s_lighting
{
	t_material	material;
	t_light		light;
	t_vec		point;
	t_vec		eyev;
	t_vec		normal;
}	t_lighting;

typedef struct s_rt
{
	t_mlx				mlx;
	t_img				img;
	t_camera			camera;
	t_ambient			ambient;
	t_light_list		lights;
	t_object_list		*scene;
}	t_rt;

#endif
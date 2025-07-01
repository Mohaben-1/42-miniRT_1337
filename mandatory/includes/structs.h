/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:41:40 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/01 19:58:13 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCTS_H
#define STRUCTS_H

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
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_rt
{
	t_mlx				mlx;
	t_img				img;
	t_camera			camera;
	t_ambient			ambient;
	t_light				light;
	t_hit_table_list	*world;
}	t_rt;


typedef struct s_vec
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
		};
		struct
		{
			float	r;
			float	g;
			float	b;
		};
	};
}	t_vec;

typedef t_vec	t_point;
typedef t_vec	t_color;

typedef struct s_light
{
	t_point		position;
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
	t_point	origin; // camera position (look_from)
	t_point	target; // what the camera is looking at (look_at)
}	t_camera;

typedef struct s_ambient
{
	t_color	color;
	double	ratio;
}	t_ambient;

typedef struct s_hit_record {
	t_point	point;          // Where the ray hit
	t_vec	normal;         // Surface normal at the hit point
	double	t;              // Ray parameter at the hit
	bool	is_front_face;  // True if the hit is on the outside
	int		object_id;      // ID/index of the object hit
	int		skip_id;        // ID of object to skip (e.g., in shadow rays)
}	t_hit_record;

	typedef struct s_material
	{
		t_color	color;
		double	ambient;
		double	diffuse;
		double	specular;
		double	shininess;
	}	t_material;

typedef struct s_sphere
{
	t_point		center;
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

// typedef struct s_cone
// {
// 	t_vec		vertex;
// 	t_vec		axis;
// 	double		h;
// 	double		angle;
// 	int			type;
// 	t_material	m;
// }				t_cone;

typedef struct s_plane
{
	t_vec		normal;
	t_vec		position;
	int			type;
	t_material	material;
}	t_plane;

typedef union u_hit_table
{
	int			type;
	t_sphere	sphere;
}	t_hit_table;

typedef struct s_hit_table_node
{
	union
	{
		void		*object;
		t_sphere	*sphere;
		t_sphere	*s;
		t_cylinder	*cylinder;
		t_cylinder	*y;
		t_plane		*plane;
		t_plane		*p;
		// t_cone		*cone;
		// t_cone		*c;
	};
	int						type;
	int						index;
	struct s_hittable_node	*next;
}	t_hit_table_node;

typedef struct s_hit_table_list
{
	t_hit_table_node	*head;
}	t_hit_table_list;

typedef struct s_ray
{
	t_point	origin;
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
		// t_cone	*cone;
	};
	t_variation		variation;
	t_ray			*ray;
	t_hit_record	*rec;
}				t_hit;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	root[2];
}	t_quadratic;

typedef struct s_lighting
{
	t_material	material;
	t_light		light;
	t_point		point;
	t_vec		eyev;
	t_vec		normal;
}	t_lighting;

#endif
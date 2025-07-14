/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:18:23 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/14 19:41:23 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_texture	*load_texture(char *path, t_rt *rt)
{
	t_texture	*texture;
	char		*actual_path;

	texture = ft_calloc(1, sizeof(t_texture));
	if (!texture)
		return (NULL);
	actual_path = path + 3;
	texture->path = actual_path;
	texture->img = mlx_xpm_file_to_image(rt->mlx.ptr, actual_path, &texture->width, &texture->height);
	if (!texture->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(actual_path, 2);
		ft_putstr_fd("\n", 2);
		free(texture);
		return (NULL);
    }
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_len, &texture->endian);
	return (texture);
}

t_color	sample_texture(t_texture *texture, double u, double v)
{
	t_color	result;
	char	*pixel;
	int		color;
	int		x;
	int		y;

	if (!texture || !texture->addr)
		return (vec_create(1, 1, 1));
	u = fmod(u, 1.0);
	v = fmod(v, 1.0);
	if (u < 0)
		u += 1.0;
	if (v < 0)
		v += 1.0;
	x = (int)(u * texture->width) % texture->width;
	y = (int)(v * texture->height) % texture->height;
	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	color = *(int *)pixel;
	result.r = ((color >> 16) & 0xFF) / 255.0;
	result.g = ((color >> 8) & 0xFF) / 255.0;
	result.b = (color & 0xFF) / 255.0;
	return (result);
}


void	free_texture(t_texture *texture, t_rt *rt)
{
	if (texture)
	{
		if (texture->img)
			mlx_destroy_image(rt->mlx.ptr, texture->img);
		free(texture);
	}
}

void	get_sphere_uv(t_vec point, t_sphere *sphere, double *u, double *v)
{
	t_vec	p;
	double	theta;
	double	phi;

	p = vec_normalize(vec_sub(point, sphere->center));
	theta = atan2(p.z, p.x);
	phi = acos(p.y);
	*u = (theta + PI) / (2.0 * PI);
	*v = phi / PI;
}

void	get_plane_uv(t_vec point, t_plane *plane, double *u, double *v)
{
	t_vec	tangent;
	t_vec	bitangent;
	t_vec	p;

	if (fabs(plane->normal.x) > 0.1)
		tangent = vec_normalize(vec_cross(plane->normal, vec_create(0, 1, 0)));
	else
		tangent = vec_normalize(vec_cross(plane->normal, vec_create(1, 0, 0)));
	bitangent = vec_cross(plane->normal, tangent);
	p = vec_sub(point, plane->position);
	*u = vec_dot(p, tangent) * 0.1;
	*v = vec_dot(p, bitangent) * 0.1;
}

void	get_cylinder_uv(t_vec point, t_cylinder *cyl, double *u, double *v)
{
	t_vec	p;
	double	theta;
	double	height;

	p = vec_sub(point, cyl->center);
	theta = atan2(p.z, p.x);
	height = vec_dot(p, cyl->axis);
	*u = (theta + PI) / (2.0 * PI);
	*v = (height + cyl->height / 2.0) / cyl->height;
}

void	get_cone_uv(t_vec point, t_cone *cone, double *u, double *v)
{
	t_vec	p;
	double	theta;
	double	height;

	p = vec_sub(point, cone->vertex);
	theta = atan2(p.z, p.x);
	height =vec_dot(p, cone->axis);
	*u = (theta + PI) / (2.0 * PI);
	*v = height / cone->height;
}

t_vec	calculate_bump_normal(t_hit_data *hit_data, t_material *material, 
	t_object *obj)
{
	double	u, v;
	t_color	bump_color;
	t_vec	perturbed_normal;
	double	bump_strength = 0.1;

	if (material->texture_type != TEX_BUMP || !material->texture)
	return (hit_data->normal);

	if (obj->type == OBJ_SPHERE)
	get_sphere_uv(hit_data->point, obj->sphere, &u, &v);
	else if (obj->type == OBJ_PLANE)
	get_plane_uv(hit_data->point, obj->plane, &u, &v);
	else if (obj->type == OBJ_CYLINDER)
	get_cylinder_uv(hit_data->point, obj->cylinder, &u, &v);
	else if (obj->type == OBJ_CONE)
	get_cone_uv(hit_data->point, obj->cone, &u, &v);
	else
	return (hit_data->normal);

	bump_color = sample_texture(material->texture, u, v);
	double height = (bump_color.r + bump_color.g + bump_color.b) / 3.0;

	t_vec tangent, bitangent;
	if (fabs(hit_data->normal.x) > 0.1)
	tangent = vec_normalize(vec_cross(hit_data->normal, vec_create(0, 1, 0)));
	else
	tangent = vec_normalize(vec_cross(hit_data->normal, vec_create(1, 0, 0)));
	bitangent = vec_cross(hit_data->normal, tangent);

	perturbed_normal = vec_add(hit_data->normal,
	vec_scale(vec_add(vec_scale(tangent, (height - 0.5) * bump_strength),
	vec_scale(bitangent, (height - 0.5) * bump_strength)), 1.0));

	return (vec_normalize(perturbed_normal));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:18:23 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 15:52:31 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

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
	height = vec_dot(p, cone->axis);
	*u = (theta + PI) / (2.0 * PI);
	*v = height / cone->height;
}

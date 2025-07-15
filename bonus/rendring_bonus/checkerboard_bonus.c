/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 16:10:29 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_color	checker_plane(t_hit *hit, t_plane *plane)
{
	long	x;
	long	y;
	long	z;

	(void)plane;
	x = (int)floor(hit->hit_data->point.x * CHECKR_SCALE);
	y = (int)floor(hit->hit_data->point.y * CHECKR_SCALE);
	z = (int)floor(hit->hit_data->point.z * CHECKR_SCALE);
	if ((x + y + z) % 2 == 0)
		return (vec_create(1, 1, 1));
	else
		return (vec_create(0, 0, 0));
}

t_color	checker_sphere(t_hit *hit, t_sphere *sphere)
{
	t_vec	p;
	double	theta;
	double	phi;
	double	u;
	double	v;

	p = vec_sub(hit->hit_data->point, sphere->center);
	theta = atan2(p.z, p.x);
	phi = acos(p.y / sphere->radius);
	u = (theta + PI) / (2.0 * PI);
	v = phi / PI;
	if (((int)floor(u * CHECKR_SCALE) + (int)floor(v * CHECKR_SCALE)) % 2 == 0)
		return (vec_create(1.0, 1.0, 1.0));
	else
		return (vec_create(0.0, 0.0, 0.0));
}

t_color	checker_cylinder(t_hit *hit, t_cylinder *cyl)
{
	t_vec	p;
	float	theta;
	float	u;
	float	v;

	p = vec_sub(hit->hit_data->point, cyl->center);
	theta = atan2(p.z, p.x);
	u = (theta + PI) / (2 * PI);
	v = p.y;
	if (((int)floor(u * CHECKR_SCALE) + (int)floor(v * CHECKR_SCALE)) % 2 == 0)
		return (vec_create(0, 0, 0));
	else
		return (vec_create(1, 1, 1));
}

t_color	apply_checkerboard(t_hit *hit, t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
		return (checker_sphere(hit, obj->sphere));
	else if (obj->type == OBJ_CYLINDER)
		return (checker_cylinder(hit, obj->cylinder));
	else if (obj->type == OBJ_CONE)
		return (checker_cone(hit, obj->cone));
	else if (obj->type == OBJ_PLANE)
		return (checker_plane(hit, obj->plane));
	return (vec_create(0, 0, 0));
}

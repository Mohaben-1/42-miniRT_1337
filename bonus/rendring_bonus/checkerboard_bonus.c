/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/12 15:36:59 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

#include <stdio.h>

#define CHECKER_SCALE 0.1

// t_color	apply_checkerboard(t_hit *hit)
// {
// 	double	scale;
// 	long	x;
// 	long	y;
// 	long	z;

// 	scale = 0.1;
// 	x = (long)(hit->hit_data->point.x / scale);
// 	y = (long)(hit->hit_data->point.y / scale);
// 	z = (long)(hit->hit_data->point.z / scale);
// 	if ((x + y + z) % 2 == 0)
// 		return (vec_create(1.0, 1.0, 1.0));
// 	else
// 		return (vec_create(0.0, 0.0, 0.0));
// }


t_color checker_plane_uv(t_hit *hit, t_plane *plane)
{
	long	x;
	long	y;
	long	z;

	(void)plane;
	x = (long)(hit->hit_data->point.x / CHECKER_SCALE);
	y = (long)(hit->hit_data->point.y / CHECKER_SCALE);
	z = (long)(hit->hit_data->point.z / CHECKER_SCALE);
	if ((x + y + z) % 2 == 0)
		return (vec_create(1.0, 1.0, 1.0));
	else
		return (vec_create(0.0, 0.0, 0.0));
}


t_color	checker_sphere_uv(t_hit *hit, t_sphere *sphere)
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
	if (((int)(u / CHECKER_SCALE) + (int)(v / CHECKER_SCALE)) % 2 == 0)
		return (vec_create(1.0, 1.0, 1.0));
	else
		return (vec_create(0.0, 0.0, 0.0));
}

t_color checker_cylinder_uv(t_hit *hit, t_cylinder *cyl)
{
    t_vec p = vec_sub(hit->hit_data->point, cyl->cap_bottom);
    t_vec axis = vec_normalize(cyl->axis);
    
    // Project point onto cylinder axis to get height
    double height = vec_dot(p, axis);
    
    // Get the radial vector (perpendicular to axis)
    t_vec radial = vec_sub(p, vec_scale(axis, height));
    
    // Calculate angle around the axis
    double angle = atan2(radial.z, radial.x);
    
    // Convert to UV coordinates
    double u = (angle + PI) / (2.0 * PI);
    double v = height / cyl->height;
    
    // Apply checkerboard pattern
    int i = (int)(u / CHECKER_SCALE);
    int j = (int)(v / CHECKER_SCALE);
    
    return ((i + j) % 2 == 0) ? vec_create(1, 1, 1) : vec_create(0, 0, 0);
}

t_color checker_cone_uv(t_hit *hit, t_cone *cone)
{
	t_vec p = vec_sub(hit->hit_data->point, cone->vertex);
	t_vec axis = vec_normalize(cone->axis);
	t_vec around = vec_normalize(vec_cross(axis, vec_create(1, 0, 0)));
	if (vec_len(around) < 1e-6)
		around = vec_normalize(vec_cross(axis, vec_create(0, 1, 0)));
	t_vec binormal = vec_cross(axis, around);

	double height = vec_dot(p, axis);
	double angle = atan2(vec_dot(p, binormal), vec_dot(p, around));

	double u = (angle + PI) / (2.0 * PI);
	double v = height / cone->height;

	int i = (int)(u / CHECKER_SCALE);
	int j = (int)(v / CHECKER_SCALE);

	return ((i + j) % 2 == 0) ? vec_create(1, 1, 1) : vec_create(0, 0, 0);
}

t_color apply_checkerboard(t_hit *hit, t_object *obj)
{
    if (obj->type == OBJ_SPHERE)
        return (checker_sphere_uv(hit, obj->sphere));
    else if (obj->type == OBJ_CYLINDER)
        return (checker_cylinder_uv(hit, obj->cylinder));
    else if (obj->type == OBJ_CONE)
        return (checker_cone_uv(hit, obj->cone));
    else if (obj->type == OBJ_PLANE)
        return (checker_plane_uv(hit, obj->plane));
    return (vec_create(0, 0, 0));
}

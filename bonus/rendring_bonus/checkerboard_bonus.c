/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/11 20:51:41 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

// t_color	apply_checker_plane(t_hit *hit)
// {
// 	double scale = 0.5;
// 	long x = (long)(hit->hit_data->point.x / scale);
// 	long z = (long)(hit->hit_data->point.z / scale);
// 	if ((x + z) % 2 == 0)
// 		return vec_create(1, 1, 1);
// 	return vec_create(0, 0, 0);
// }

t_color checker_plane_uv(t_hit *hit, double scale)
{
	t_vec p = hit->hit_data->point;
	int u = (int)(p.x / scale);
	int v = (int)(p.z / scale);
	return ((u + v) % 2 == 0) ? vec_create(1, 1, 1) : vec_create(0, 0, 0);
}

t_color checker_sphere_uv(t_hit *hit, double scale)
{
	t_vec p = vec_sub(hit->hit_data->point, hit->sphere->center);
	double theta = atan2(p.z, p.x);
	double phi = acos(p.y / hit->sphere->radius);
	int u = (int)(theta / (2 * M_PI / scale));
	int v = (int)(phi / (M_PI / scale));
	return ((u + v) % 2 == 0) ? vec_create(1, 1, 1) : vec_create(0, 0, 0);
}

t_color checker_cylinder_uv(t_hit *hit, double scale)
{
	t_vec p = vec_sub(hit->hit_data->point, hit->cyl->center);
	t_vec up = hit->cyl->axis;
	t_vec around = vec_normalize(vec_cross(up, vec_create(1, 0, 0)));
	if (vec_len(around) == 0)
		around = vec_normalize(vec_cross(up, vec_create(0, 1, 0)));
	t_vec binormal = vec_cross(up, around);
	double height = vec_dot(p, up);
	double angle = atan2(vec_dot(p, binormal), vec_dot(p, around));
	int u = (int)(angle / (2 * M_PI / scale));
	int v = (int)(height / scale);
	return ((u + v) % 2 == 0) ? vec_create(1, 1, 1) : vec_create(0, 0, 0);
}

t_color checker_cone_uv(t_hit *hit, double scale)
{
	t_vec p = vec_sub(hit->hit_data->point, hit->cone->vertex);
	t_vec axis = vec_normalize(hit->cone->axis);
	t_vec around = vec_normalize(vec_cross(axis, vec_create(1, 0, 0)));
	if (vec_len(around) == 0)
		around = vec_normalize(vec_cross(axis, vec_create(0, 1, 0)));
	t_vec binormal = vec_cross(axis, around);
	double height = vec_dot(p, axis);
	double angle = atan2(vec_dot(p, binormal), vec_dot(p, around));
	int u = (int)(angle / (2 * M_PI / scale));
	int v = (int)(height / scale);
	return ((u + v) % 2 == 0) ? vec_create(1, 1, 1) : vec_create(0, 0, 0);
}

t_color	apply_checkerboard(t_hit *hit)
{
	if (hit->hit_data->object_id == OBJ_SPHERE)
		return  checker_sphere_uv(hit, 0.2);
	else if (hit->hit_data->object_id == OBJ_CYLINDER)
		return  checker_cylinder_uv(hit, 0.2);
	else if (hit->hit_data->object_id == OBJ_CONE)
		return  checker_cone_uv(hit, 0.2);
	else
		return  checker_plane_uv(hit, 0.2);
	return vec_create(1.0, 0.0, 1.0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/10 20:30:55 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_color	get_checkerboard_pattern(t_vec point)
{
	double	u;
	double	v;
	int		checker_u;
	int		checker_v;

	u = point.x * 4.0;
	v = point.z * 4.0;
	checker_u = (int)floor(u);
	checker_v = (int)floor(v);
	if ((checker_u + checker_v) % 2 == 0)
		return (vec_create(1.0, 1.0, 1.0));
	else
		return (vec_create(0.0, 0.0, 0.0));
}

t_color	get_sphere_checkerboard(t_vec point, t_vec center)
{
	double	theta;
	double	phi;
	double	u;
	double	v;
	int		checker_u;
	int		checker_v;
	t_vec	relative_point;

	relative_point = vec_sub(point, center);
	relative_point = vec_normalize(relative_point);
	theta = atan2(relative_point.z, relative_point.x);
	phi = acos(relative_point.y);
	u = (theta + PI) / (2.0 * PI);
	v = phi / PI;
	u *= 4.0;
	v *= 4.0;
	checker_u = (int)floor(u);
	checker_v = (int)floor(v);
	if ((checker_u + checker_v) % 2 == 0)
		return (vec_create(1.0, 1.0, 1.0));
	else
		return (vec_create(0.0, 0.0, 0.0));
}

t_color	get_plane_checkerboard(t_vec point, t_vec plane_pos, t_vec plane_normal)
{
	t_vec	u_axis;
	t_vec	v_axis;
	t_vec	relative_point;
	double	u;
	double	v;
	int		checker_u;
	int		checker_v;

	if (fabs(plane_normal.y) < 0.9)
		u_axis = vec_normalize(vec_cross(plane_normal, vec_create(0, 1, 0)));
	else
		u_axis = vec_normalize(vec_cross(plane_normal, vec_create(1, 0, 0)));
	v_axis = vec_normalize(vec_cross(plane_normal, u_axis));
	relative_point = vec_sub(point, plane_pos);
	u = vec_dot(relative_point, u_axis) * 4.0;
	v = vec_dot(relative_point, v_axis) * 4.0;
	checker_u = (int)floor(u);
	checker_v = (int)floor(v);
	if ((checker_u + checker_v) % 2 == 0)
		return (vec_create(1.0, 1.0, 1.0));
	else
		return (vec_create(0.0, 0.0, 0.0));
}

t_color	get_material_color(t_material material, t_hit *hit)
{
	t_object	*obj;

	if (material.texture_type == TEX_CHECKER)
	{
		if (hit->hit_data->object_id < 0)
			return (material.color);
		obj = get_object_by_id(hit->hit_data->object_id);
		if (obj->type == OBJ_SPHERE)
			return (get_sphere_checkerboard(hit->hit_data->point, obj->sphere->center));
		else if (obj->type == OBJ_PLANE)
			return (get_plane_checkerboard(hit->hit_data->point, obj->plane->position, obj->plane->normal));
		else
			return get_checkerboard_pattern(hit->hit_data->point);
	}
	return (material.color);
}

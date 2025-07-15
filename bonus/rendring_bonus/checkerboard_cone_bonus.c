/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_cone_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 16:16:10 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static t_vec	calculate_cone_vectors(t_cone *cone)
{
	t_vec	axis;
	t_vec	around;

	axis = vec_normalize(cone->axis);
	around = vec_normalize(vec_cross(axis, vec_create(1, 0, 0)));
	if (vec_len(around) < 1e-6)
		around = vec_normalize(vec_cross(axis, vec_create(0, 1, 0)));
	return (around);
}

static void	get_cone_uv_coords(t_vec p, t_cone *cone, double *u, double *v)
{
	t_vec	axis;
	t_vec	around;
	t_vec	binormal;
	double	height;
	double	angle;

	axis = vec_normalize(cone->axis);
	around = calculate_cone_vectors(cone);
	binormal = vec_cross(axis, around);
	height = vec_dot(p, axis);
	angle = atan2(vec_dot(p, binormal), vec_dot(p, around));
	*u = (angle + PI) / (2.0 * PI);
	*v = height / cone->height;
}

t_color	checker_cone(t_hit *hit, t_cone *cone)
{
	t_vec	p;
	double	u;
	double	v;
	int		checker_sum;

	p = vec_sub(hit->hit_data->point, cone->vertex);
	get_cone_uv_coords(p, cone, &u, &v);
	checker_sum = (int)floor(u * CHECKR_SCALE) + (int)floor(v * CHECKR_SCALE);
	if (checker_sum % 2 == 0)
		return (vec_create(0, 0, 0));
	else
		return (vec_create(1, 1, 1));
}

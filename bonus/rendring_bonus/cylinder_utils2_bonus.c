/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:16:38 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 22:57:21 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_hit	init_hit(t_cylinder *cyl, t_ray *ray, t_variation t,
	t_hit_data *hit_data)
{
	t_hit	hit;

	hit.cyl = cyl;
	hit.ray = ray;
	hit.variation = t;
	hit.hit_data = hit_data;
	return (hit);
}

t_quadratic	init_quadra(t_vec ray_dir, t_vec v, double radius)
{
	t_quadratic	quadra;

	quadra.a = vec_len_sqd(v);
	quadra.b = 2 * vec_dot(ray_dir, v);
	quadra.c = vec_len_sqd(ray_dir) - radius * radius;
	quadra.discriminant = quadra.b * quadra.b - 4 * quadra.a * quadra.c;
	return (quadra);
}

void	update_hit_data(t_hit_data *hit_data, t_vec hit_point,
	t_vec cap_base, t_vec axis)
{
	hit_data->normal = vec_unit(vec_sub(hit_point,
				vec_add(cap_base, vec_scale(axis,
						vec_dot(vec_sub(hit_point, cap_base), axis)))));
}

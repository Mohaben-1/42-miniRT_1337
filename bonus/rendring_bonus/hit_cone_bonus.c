/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:47:26 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/16 12:08:33 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	in_bound(double height, double root, t_variation t,
		double cone_height)
{
	return (height >= 0 && height <= cone_height
		&& root >= t.min && root <= t.max);
}

int	any_root_valid(double height[], double root[], t_variation t, double h)
{
	return (in_bound(height[0], root[0], t, h)
		|| in_bound(height[1], root[1], t, h));
}

int	hit_cone(t_cone cone, t_ray *ray, t_variation t, t_hit_data *hit_data)
{
	double		h[2];
	t_vec		point[2];
	t_quadratic	quadra;

	quadra = solve_cone_quadra(ray, vec_sub(ray->origin, cone.vertex), cone);
	if (quadra.discriminant < 0)
		return (0);
	quadra = find_quadra_root(quadra);
	point[0] = ray_at(*ray, quadra.root[0]);
	h[0] = vec_dot(cone.axis, vec_sub(point[0], cone.vertex));
	point[1] = ray_at(*ray, quadra.root[1]);
	h[1] = vec_dot(cone.axis, vec_sub(point[1], cone.vertex));
	if (any_root_valid(h, quadra.root, t, cone.height))
	{
		if (in_bound(h[0], quadra.root[0], t, cone.height) && 
			(!in_bound(h[1], quadra.root[1], t, cone.height)
				|| quadra.root[0] < quadra.root[1]))
			set_data_hit_cone(hit_data, quadra.root[0], point[0]);
		else
			set_data_hit_cone(hit_data, quadra.root[1], point[1]);
		update_cone_hit_data(cone, ray, hit_data);
		return (1);
	}
	return (0);
}

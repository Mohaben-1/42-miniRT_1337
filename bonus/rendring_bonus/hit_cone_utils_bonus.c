/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:47:26 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/16 13:15:41 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_quadratic	find_quadra_root(t_quadratic quadra)
{
	quadra.root[0] = (-quadra.b - sqrt(quadra.discriminant)) / (2 * quadra.a);
	quadra.root[1] = (-quadra.b + sqrt(quadra.discriminant)) / (2 * quadra.a);
	return (quadra);
}

void	set_data_hit_cone(t_hit_data *hit_data, double root, t_vec point)
{
	hit_data->t = root;
	hit_data->point = point;
}

t_quadratic	solve_cone_quadra(t_ray *ray, t_vec origin_vertex, t_cone cone)
{
	t_quadratic	quadra;
	double		k;

	k = tan(cone.angle) * tan(cone.angle);
	quadra.a = vec_dot(
			ray->direction, ray->direction)
		- (1 + k) * pow(vec_dot(ray->direction, cone.axis), 2);
	quadra.b = 2 * (vec_dot(ray->direction, origin_vertex) - (1 + k)
			* vec_dot(ray->direction, cone.axis)
			* vec_dot(origin_vertex, cone.axis));
	quadra.c = vec_dot(origin_vertex, origin_vertex)
		- (1 + k) * pow(vec_dot(origin_vertex, cone.axis), 2);
	quadra.discriminant = quadra.b * quadra.b - 4 * quadra.a * quadra.c;
	return (quadra);
}

void	update_cone_hit_data(t_cone cone, t_ray *ray, t_hit_data *hit_data)
{
	t_vec	point_on_axis;

	point_on_axis = vec_add(cone.vertex, vec_scale(cone.axis, 
				vec_dot(vec_sub(hit_data->point, cone.vertex), cone.axis)));
	hit_data->normal = vec_unit(vec_sub(hit_data->point, point_on_axis));
	determine_surface_normal(hit_data, ray, &hit_data->normal);
}

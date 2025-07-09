/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:03:05 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/08 13:27:56 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	hit_plane(t_plane plane, t_ray *ray, t_variation t, t_hit_data *hit_data)
{
	double	v_distance;
	double	v_origin;
	double	temp;

	v_distance = vec_dot(plane.normal, ray->direction);
	if (fabs(v_distance) < 1e-8)
		return (0);
	v_origin = -(vec_dot(plane.normal, ray->origin)
			- vec_dot(plane.normal, plane.position));
	temp = v_origin / v_distance;
	if (temp > t.max || temp < t.min)
		return (0);
	hit_data->t = temp;
	hit_data->point = ray_at(*ray, hit_data->t);
	hit_data->normal = plane.normal;
	if (vec_dot(plane.normal, ray->direction) > 0.00001)
		vec_negative(&hit_data->normal);
	return (1);
}

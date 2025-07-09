/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:34:13 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 22:57:18 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

double	compute_t_cap(t_vec aot, t_ray ray, t_vec axis)
{
	if (fabs(vec_dot(ray.direction, axis)) < 1e-6)
		return (-1);
	return (vec_dot(aot, axis) / vec_dot(ray.direction, axis));
}

int	find_hit_result(t_hit hit, double t_cap[2], t_vec point_on_cap[2])
{
	int	hit_cap[2];

	hit_cap[0] = check_cap_intersection(&hit, t_cap[0], point_on_cap[0], 1);
	hit_cap[1] = check_cap_intersection(&hit, t_cap[1], point_on_cap[1], 0);
	if (hit_cap[0] && hit_cap[1])
	{
		if (t_cap[0] < t_cap[1])
			return (check_cap_intersection(&hit, t_cap[0], point_on_cap[0], 1));
		else
			return (check_cap_intersection(&hit, t_cap[1], point_on_cap[1], 0));
	}
	else if (hit_cap[0])
		return (check_cap_intersection(&hit, t_cap[0], point_on_cap[0], 1));
	else if (hit_cap[1])
		return (check_cap_intersection(&hit, t_cap[1], point_on_cap[1], 0));
	return (0);
}

int	hit_caps(t_cylinder c, t_ray *ray, t_variation t, t_hit_data *hit_data)
{
	t_hit		hit;
	double		t_cap[2];
	t_vec		point_on_cap[2];
	t_vec		to_cap[2];

	hit.cyl = &c;
	hit.ray = ray;
	hit.variation = t;
	hit.hit_data = hit_data;
	to_cap[0] = vec_sub(c.cap_bottom, ray->origin);
	to_cap[1] = vec_sub(c.cap_top, ray->origin);
	t_cap[0] = compute_t_cap(to_cap[0], *ray, c.axis);
	t_cap[1] = compute_t_cap(to_cap[1], *ray, c.axis);
	point_on_cap[0] = ray_at(*ray, t_cap[0]);
	point_on_cap[1] = ray_at(*ray, t_cap[1]);
	return (find_hit_result(hit, t_cap, point_on_cap));
}

int	is_valid_intersection(double h, double rt, t_hit *hit)
{
	return (h >= 0 && h <= hit->cyl->height
		&& rt >= hit->variation.min && rt <= hit->variation.max);
}

void	set_hit_data(t_hit *hit, double rt, t_vec point)
{
	hit->hit_data->t = rt;
	hit->hit_data->point = point;
}

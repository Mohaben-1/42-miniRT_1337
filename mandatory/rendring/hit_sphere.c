/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:44:37 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/10 10:33:02 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_scale(ray.direction, t)));
}

static int	validate_quadratic_root(t_variation t, t_vec delta,
			double sqrt_discr, double *root)
{
	if (t.min > *root || *root > t.max)
	{
		*root = (-delta.y + sqrt_discr) / delta.x;
		if (t.min > *root || *root > t.max)
			return (0);
	}
	return (1);
}

static t_vec	compute_normal_at_hit(t_hit_data *hit_data, t_sphere sphere)
{
	t_vec	new;

	new = vec_div(vec_sub(hit_data->point, sphere.center), sphere.radius);
	return (new);
}

int	hit_sphere(t_sphere sphere, t_ray *ray, t_variation t, t_hit_data *hit_data)
{
	t_vec		distance;
	t_vec		delta;
	t_vec		out_normal;
	double		discr;
	double		root;

	distance = vec_sub(ray->origin, sphere.center);
	delta.x = vec_len_sqd(ray->direction);
	delta.y = vec_dot(distance, ray->direction);
	delta.z = vec_len_sqd(distance) - sphere.radius * sphere.radius;
	discr = delta.y * delta.y - (delta.x * delta.z);
	if (discr < 0)
		return (0);
	root = (-delta.y - sqrt(discr)) / delta.x;
	if (!validate_quadratic_root(t, delta, sqrt(discr), &root))
		return (0);
	hit_data->t = root;
	hit_data->point = ray_at(*ray, hit_data->t);
	out_normal = compute_normal_at_hit(hit_data, sphere);
	determine_surface_normal(hit_data, ray, &out_normal);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:33:37 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/08 20:41:37 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_cap_intersection(t_hit *hit, double t_val,
	t_vec point, int is_bottom)
{
	const double	epsilon = 1e-6;
	double			radius;
	t_vec			cap;

	if (is_bottom)
		cap = hit->cyl->cap_bottom;
	else
		cap = hit->cyl->cap_top;
	radius = vec_len(vec_sub(point, cap));
	if (t_val >= hit->variation.min && t_val <= hit->variation.max
		&& radius <= hit->cyl->radius - epsilon)
	{
		hit->hit_data->t = t_val;
		hit->hit_data->point = point;
		if (is_bottom)
			hit->hit_data->normal = vec_scale(hit->cyl->axis, -1);
		else
			hit->hit_data->normal = hit->cyl->axis;
		determine_surface_normal(hit->hit_data, hit->ray,
			&hit->hit_data->normal);
		return (1);
	}
	return (0);
}

static void	compute_ray_hits_height(double root[2],
	t_hit *hit, t_vec hit_points[2], double heights[2])
{
	hit_points[0] = ray_at(*hit->ray, root[0]);
	hit_points[1] = ray_at(*hit->ray, root[1]);
	heights[0] = vec_dot(hit->cyl->axis, vec_sub(hit_points[0],
				hit->cyl->cap_bottom));
	heights[1] = vec_dot(hit->cyl->axis, vec_sub(hit_points[1],
				hit->cyl->cap_bottom));
}

static int	select_vld_body_hit(double roots[2], t_hit *hit,
	int vld_inter1, int vld_inter2)
{
	t_vec		hit_points[2];
	double		heights[2];

	compute_ray_hits_height(roots, hit, hit_points, heights);
	vld_inter1 = is_valid_intersection(heights[0], roots[0], hit);
	vld_inter2 = is_valid_intersection(heights[1], roots[1], hit);
	if (vld_inter1 && vld_inter2)
	{
		if (roots[0] < roots[1])
			set_hit_data(hit, roots[0], hit_points[0]);
		else
			set_hit_data(hit, roots[1], hit_points[1]);
		return (1);
	}
	else if (vld_inter1)
	{
		set_hit_data(hit, roots[0], hit_points[0]);
		return (1);
	}
	else if (vld_inter2)
	{
		set_hit_data(hit, roots[1], hit_points[1]);
		return (1);
	}
	return (0);
}

static int	chose_closest_hit(t_hit *hit, int did_hit_body)
{
	t_hit_data		cap_hit_data;
	int				did_hit_cap;

	did_hit_cap = hit_caps(*hit->cyl, hit->ray, hit->variation, &cap_hit_data);
	if (did_hit_cap && did_hit_body)
	{
		if (cap_hit_data.t < hit->hit_data->t)
		{
			*hit->hit_data = cap_hit_data;
		}
	}
	else if (did_hit_cap)
	{
		*hit->hit_data = cap_hit_data;
	}
	else if (!did_hit_body)
		return (0);
	return (1);
}

int	hit_cylinder(t_cylinder *cyl, t_ray *ray, t_variation t,
	t_hit_data *hit_data)
{
	t_hit		hit;
	t_vec		v;
	t_vec		origin_proj;
	t_vec		dir_proj;
	t_quadratic	quadra;

	hit = init_hit(cyl, ray, t, hit_data);
	origin_proj = vec_sub(ray->origin, cyl->cap_bottom);
	dir_proj = project_onto_plane(origin_proj, cyl->axis);
	v = project_onto_plane(ray->direction, cyl->axis);
	quadra = init_quadra(dir_proj, v, cyl->radius);
	if (quadra.discriminant < 0)
		return (0);
	quadra.root[0] = (-quadra.b - sqrt(quadra.discriminant)) / (2 * quadra.a);
	quadra.root[1] = (-quadra.b + sqrt(quadra.discriminant)) / (2 * quadra.a);
	if (!chose_closest_hit(&hit, select_vld_body_hit(quadra.root, &hit, 0, 0)))
		return (0);
	update_hit_data(hit_data, hit_data->point, cyl->cap_bottom, cyl->axis);
	determine_surface_normal(hit_data, ray, &hit_data->normal);
	if (!chose_closest_hit(&hit, select_vld_body_hit(quadra.root, &hit, 0, 0)))
		return (0);
	return (1);
}

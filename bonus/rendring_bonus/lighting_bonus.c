/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:51:43 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 22:55:08 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_vec	normalize(t_vec vector)
{
	t_vec		normalize;
	double		length;

	length = vec_len(vector);
	if (length == 0)
		return (vector);
	normalize.x = vector.x / length;
	normalize.y = vector.y / length;
	normalize.z = vector.z / length;
	return (normalize);
}

static void	normalize_result(t_color *colors)
{
	if (fabs(colors[RESULT].x) > 1)
		colors[RESULT].x = 1;
	if (fabs(colors[RESULT].y) > 1)
		colors[RESULT].y = 1;
	if (fabs(colors[RESULT].z) > 1)
		colors[RESULT].z = 1;
}

static t_color	get_final_color(t_color *colors)
{
	t_color	result;

	result = vec_create(colors[RESULT].x, colors[RESULT].y,
			colors[RESULT].z);
	return (result);
}

static void	zero_light(t_color *diffuse, t_color *specular)
{
	*diffuse = vec_create(0, 0, 0);
	*specular = vec_create(0, 0, 0);
}

t_color	compute_lighting(t_material m, t_light light, t_hit *hit, int in_shadow)
{
	t_color		combined_color;
	t_color		colors[4];
	t_vec		reflect_vec;
	t_vec		light_vec;
	double		light_dot_normal;

	combined_color = vec_product(vec_scale(m.color,
				light.intensity), light.color);
	light_vec = normalize(vec_sub(light.position, hit->hit_data->point));
	colors[AMBIENT] = vec_scale(combined_color, m.ambient);
	light_dot_normal = fmax(0, vec_dot(light_vec, hit->hit_data->normal));
	colors[DIFFUSE] = vec_scale(combined_color, m.diffuse * light_dot_normal);
	reflect_vec = vec_reflect(vec_negative(&light_vec), hit->hit_data->normal);
	colors[SPECULAR] = vec_scale(light.color, m.specular
			* pow(vec_dot(reflect_vec, hit->ray->direction), m.shininess));
	if (!(vec_dot(reflect_vec, hit->ray->direction) > 0))
		colors[SPECULAR] = vec_create(0, 0, 0);
	if (!(light_dot_normal >= 0 && !in_shadow))
		zero_light(&colors[DIFFUSE], &colors[SPECULAR]);
	colors[RESULT] = vec_add(vec_add(colors[DIFFUSE],
				colors[SPECULAR]), colors[AMBIENT]);
	normalize_result(colors);
	return (get_final_color(colors));
}

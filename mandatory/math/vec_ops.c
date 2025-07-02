/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:08:20 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/02 12:22:10 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_create(double x, double y, double z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_color	color_create(double r, double g, double b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	return (add);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	t_vec	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	return (sub);
}

t_vec	vec_scale(t_vec v, double s)
{
	t_vec	scale;

	scale.x = v.x * s;
	scale.y = v.y * s;
	scale.z = v.z * s;
	return (scale);
}

double	vec_dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_len(t_vec v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec	vec_normalize(t_vec v)
{
	return (vec_scale(v, 1.0 / vec_len(v)));
}

t_vec	vec_cross(t_vec a, t_vec b)
{
	t_vec result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

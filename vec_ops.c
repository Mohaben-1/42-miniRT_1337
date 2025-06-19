/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:08:20 by mohaben-          #+#    #+#             */
/*   Updated: 2025/06/19 19:45:03 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	return (add);
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	return (sub);
}

t_vec3	vec_scale(t_vec3 v, double s)
{
	t_vec3	scale;

	scale.x = v.x * s;
	scale.y = v.y * s;
	scale.z = v.z * s;
	return (scale);
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_len(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec3	vec_normalize(t_vec3 v)
{
	return (vec_scale(v, 1.0 / vec_len(v)));
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3 result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

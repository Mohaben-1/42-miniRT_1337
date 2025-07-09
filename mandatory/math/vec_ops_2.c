/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:08:20 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/08 20:28:50 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec	vec_cross(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_vec	vec_div(t_vec vec, double value)
{
	t_vec	new;

	new.x = vec.x / value;
	new.y = vec.y / value;
	new.z = vec.z / value;
	return (new);
}

t_vec	vec_negative(t_vec *vec)
{
	vec->x *= -1;
	vec->y *= -1;
	vec->z *= -1;
	return (*vec);
}

t_vec	vec_product(t_vec u, t_vec v)
{
	t_vec	new;

	new.x = u.x * v.x;
	new.y = u.y * v.y;
	new.z = u.z * v.z;
	return (new);
}

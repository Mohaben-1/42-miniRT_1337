/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:25:43 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/09 20:21:11 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_vec	vec_reflect(t_vec v, t_vec n)
{
	t_vec			result;
	const double	dot_product = 2 * (v.x * n.x + v.y * n.y + v.z * n.z);

	result.x = v.x - dot_product * n.x;
	result.y = v.y - dot_product * n.y;
	result.z = v.z - dot_product * n.z;
	return (result);
}

double	vec_len_sqd(const t_vec vector)
{
	return ((vector.x * vector.x)
		+ (vector.y * vector.y)
		+ (vector.z * vector.z));
}

double	vec_len(t_vec v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec	vec_normalize(t_vec v)
{
	return (vec_scale(v, 1.0 / vec_len(v)));
}

t_vec	vec_unit(t_vec vector)
{
	return (vec_div(vector, vec_len(vector)));
}

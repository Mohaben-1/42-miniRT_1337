/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_surface_normal_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:35:04 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/15 22:39:21 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	determine_surface_normal(t_hit_data *hit_data, t_ray *ray,
		t_vec *out_normal)
{
	hit_data->is_front_face = vec_dot(ray->direction, *out_normal) < 0;
	if (hit_data->is_front_face)
		hit_data->normal = *out_normal;
	else
		hit_data->normal = vec_negative(out_normal);
}

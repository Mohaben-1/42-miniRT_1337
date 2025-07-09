/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_surface_normal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:35:04 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/08 15:52:22 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	determine_surface_normal(t_hit_data *rec, t_ray *ray, t_vec *out_normal)
{
	rec->is_front_face = vec_dot(ray->direction, *out_normal) < 0;
	if (rec->is_front_face)
		rec->normal = *out_normal;
	else
		rec->normal = vec_negative(out_normal);
}

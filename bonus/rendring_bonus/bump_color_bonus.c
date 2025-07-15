/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:50:45 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 19:51:20 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_color	apply_png_texture(t_hit *hit, t_object *obj, t_material *material)
{
	double	u;
	double	v;
	
	if (!material->texture || !material->texture->texture)
		return (material->color);
	if (obj->type == OBJ_SPHERE)
		get_sphere_uv(hit->hit_data->point, obj->sphere, &u, &v);
	else if (obj->type == OBJ_PLANE)
		get_plane_uv(hit->hit_data->point, obj->plane, &u, &v);
	else if (obj->type == OBJ_CYLINDER)
		get_cylinder_uv(hit->hit_data->point, obj->cylinder, &u, &v);
	else if (obj->type == OBJ_CONE)
		get_cone_uv(hit->hit_data->point, obj->cone, &u, &v);
	else
		return (material->color);
	return (sample_texture(material->texture, u, v));
}


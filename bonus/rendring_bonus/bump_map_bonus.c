/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:18:23 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 22:38:21 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static void	get_object_uv(t_hit_data *hit_data, t_object *obj,
	double *u, double *v)
{
	if (obj->type == OBJ_SPHERE)
		get_sphere_uv(hit_data->point, obj->sphere, u, v);
	else if (obj->type == OBJ_PLANE)
		get_plane_uv(hit_data->point, obj->plane, u, v);
	else if (obj->type == OBJ_CYLINDER)
		get_cylinder_uv(hit_data->point, obj->cylinder, u, v);
	else if (obj->type == OBJ_CONE)
		get_cone_uv(hit_data->point, obj->cone, u, v);
}

static void	calculate_tangent_vectors(t_vec normal, t_vec *tangent,
	t_vec *bitangent)
{
	t_vec	up;

	if (fabs(normal.y) < 0.9)
		up = vec_create(0, 1, 0);
	else
		up = vec_create(1, 0, 0);
	*tangent = vec_normalize(vec_cross(up, normal));
	*bitangent = vec_normalize(vec_cross(normal, *tangent));
}

static t_vec	apply_bump_perturbation(t_vec normal, t_vec tangent,
	t_vec bitangent, double height)
{
	t_vec	perturbation;
	t_vec	tangent_offset;
	t_vec	bitangent_offset;
	double	bump_strength;

	bump_strength = 0.5;
	tangent_offset = vec_scale(tangent, (height - 0.5) * bump_strength);
	bitangent_offset = vec_scale(bitangent, (height - 0.5) * bump_strength);
	perturbation = vec_add(tangent_offset, bitangent_offset);
	return (vec_normalize(vec_add(normal, perturbation)));
}

static double	get_bump_height(t_material *material, double u, double v)
{
	t_color	bump_color;
	double	height;

	bump_color = sample_texture(material->texture, u, v);
	height = 0.299 * bump_color.r + 0.587 * bump_color.g + 0.114 * bump_color.b;
	height = (height - 0.5) * 2.0 + 0.5;
	height = fmax(0.0, fmin(1.0, height));
	return (height);
}

t_vec	calculate_bump_normal(t_hit_data *hit_data, t_material *material,
	t_object *obj)
{
	t_vec	tangent;
	t_vec	bitangent;
	double	height;
	double	u;
	double	v;

	if (material->texture_type != TEX_BUMP || !material->texture)
		return (hit_data->normal);
	get_object_uv(hit_data, obj, &u, &v);
	if (obj->type != OBJ_SPHERE && obj->type != OBJ_PLANE
		&& obj->type != OBJ_CYLINDER && obj->type != OBJ_CONE)
		return (hit_data->normal);
	height = get_bump_height(material, u, v);
	calculate_tangent_vectors(hit_data->normal, &tangent, &bitangent);
	return (apply_bump_perturbation(hit_data->normal, tangent,
			bitangent, height));
}

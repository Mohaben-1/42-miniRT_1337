/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:36:53 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/16 13:35:01 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static int	is_shadowed(t_vec point, t_light light,
				t_object_list *scene, int skip_id)
{
	t_vec			shadow_vec;
	t_ray			shadow_ray;
	t_hit_data		temp_record;
	t_variation		t_range;
	t_hit			hit;

	shadow_vec = vec_sub(light.position, point);
	shadow_ray.origin = vec_add(point, vec_scale(vec_unit(shadow_vec), 1e-4));
	shadow_ray.direction = vec_normalize(shadow_vec);
	t_range.min = 0;
	t_range.max = HUGE_VAL;
	temp_record.skip_id = skip_id;
	hit.hit_data = &temp_record;
	hit.ray = &shadow_ray;
	if (is_in_shadow(scene, t_range, &hit, skip_id))
	{
		if (temp_record.t < vec_len(shadow_vec))
			return (1);
	}
	return (0);
}

static void	process_texture(t_material *material, t_hit *hit, t_object *hit_obj)
{
	if (material->texture_type == TEX_CHECKER)
		material->color = apply_checkerboard(hit, hit_obj);
	else if (material->texture_type == TEX_BUMP)
	{
		hit->hit_data->normal = calculate_bump_normal(hit->hit_data,
				material, hit_obj);
	}
}

t_color	calculate_lighting_contribution(t_material material,
	t_light_list *lights, t_hit *hit, t_object_list *scene)
{
	t_light_list	*current;
	t_color			final_color;
	t_color			light_contribution;
	int				in_shadow;

	final_color = vec_create(0, 0, 0);
	current = lights;
	while (current)
	{
		in_shadow = is_shadowed(hit->hit_data->point, current->light, scene,
				hit->hit_data->object_id);
		vec_negative(&hit->ray->direction);
		light_contribution = compute_lighting(material, current->light,
				hit, in_shadow);
		final_color = vec_add(final_color, light_contribution);
		current = current->next;
	}
	return (final_color);
}

t_color	compute_ray_color(t_ray ray, t_object_list *scene, t_light_list *lights)
{
	t_hit			hit;
	t_hit_data		hit_data;
	t_color			final_color;
	t_material		material;
	t_object		*hit_obj;

	hit.variation.min = 0;
	hit.variation.max = HUGE_VAL;
	hit.ray = &ray;
	hit_data = init_hit_data();
	hit.hit_data = &hit_data;
	if (find_closest_hit(scene, hit.ray, hit.variation, hit.hit_data))
	{
		material = get_material(scene, hit.hit_data->object_id);
		hit_obj = get_object_by_id(scene, hit_data.object_id);
		process_texture(&material, &hit, hit_obj);
		final_color = calculate_lighting_contribution(material, lights,
				&hit, scene);
		final_color.r = fmin(1.0, final_color.r);
		final_color.g = fmin(1.0, final_color.g);
		final_color.b = fmin(1.0, final_color.b);
		return (final_color);
	}
	return (vec_create(0, 0, 0));
}

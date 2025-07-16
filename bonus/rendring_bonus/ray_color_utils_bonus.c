/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:36:53 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/16 13:34:58 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_material	get_material(t_object_list *scene, int id)
{
	t_material	material;
	t_object	*current;

	current = scene->head;
	while (current)
	{
		if (id == current->id && current->type == OBJ_PLANE)
			material = current->plane->material;
		else if (id == current->id && current->type == OBJ_SPHERE)
			material = current->sphere->material;
		else if (id == current->id && current->type == OBJ_CYLINDER)
			material = current->cylinder->material;
		else if (id == current->id && current->type == OBJ_CONE)
			material = current->cone->material;
		current = current->next;
	}
	return (material);
}

t_hit_data	init_hit_data(void)
{
	t_hit_data	new;

	new.point = vec_create(0.0, 0.0, 0.0);
	new.normal = vec_create(0.0, 0.0, 0.0);
	new.t = 0.0;
	new.is_front_face = false;
	new.object_id = -1;
	new.skip_id = -1;
	return (new);
}

t_object	*get_object_by_id(t_object_list *scene, int id)
{
	t_object	*obj;

	obj = scene->head;
	while (obj)
	{
		if (obj->id == id)
			return (obj);
		obj = obj->next;
	}
	return (NULL);
}

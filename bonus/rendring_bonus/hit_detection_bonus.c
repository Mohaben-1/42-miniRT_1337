/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detection_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:19:39 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/15 11:22:32 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	set_closest_hit(double *closest, t_hit_data *tmp_hit,
	t_hit_data *closest_hit, int obj_id)
{
	*closest = tmp_hit->t;
	*closest_hit = *tmp_hit;
	closest_hit->object_id = obj_id;
	return (1);
}

int	find_closest_hit(t_object_list *list, t_ray *ray,
			t_variation t, t_hit_data *closest_hit)
{
	t_object	*obj;
	t_hit_data	tmp_hit;
	t_variation	current_t;
	double		close_t;
	int			hited;

	hited = 0;
	close_t = t.max;
	obj = list->head;
	while (obj)
	{
		current_t.min = t.min;
		current_t.max = close_t;
		if (obj->type == OBJ_SPHERE
			&& hit_sphere(*(obj->sphere), ray, current_t, &tmp_hit))
			hited = set_closest_hit(&close_t, &tmp_hit, closest_hit, obj->id);
		else if (obj->type == OBJ_PLANE
			&& hit_plane(*(obj->plane), ray, current_t, &tmp_hit))
			hited = set_closest_hit(&close_t, &tmp_hit, closest_hit, obj->id);
		else if (obj->type == OBJ_CONE && hit_cone(*(obj->cone), ray, current_t, &tmp_hit))
			hited = set_closest_hit(&close_t, &tmp_hit, closest_hit, obj->id);
		else if (obj->type == OBJ_CYLINDER
			&& hit_cylinder(obj->cylinder, ray, current_t, &tmp_hit))
			hited = set_closest_hit(&close_t, &tmp_hit, closest_hit, obj->id);
		obj = obj->next;
	}
	return (hited);
}

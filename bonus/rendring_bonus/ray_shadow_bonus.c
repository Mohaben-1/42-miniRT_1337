/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shadow_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:45:39 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 23:18:28 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static int	init_shadow_variables(double *closest, t_variation t)
{
	*closest = t.max;
	return (0);
}

static void	set_t_var(t_variation *t_var, t_variation t, double closest)
{
	t_var->min = t.min;
	t_var->max = closest;
}

static bool	object_hit(t_object *obj, t_ray *ray, t_variation t,
	t_hit_data *hit_data)
{
	if (obj->type == OBJ_SPHERE)
		return (hit_sphere(*(obj->sphere), ray, t, hit_data));
	if (obj->type == OBJ_PLANE)
		return (hit_plane(*(obj->plane), ray, t, hit_data));
	if (obj->type == OBJ_CONE)
		return (hit_cone(*(obj->cone), ray, t, hit_data));
	if (obj->type == OBJ_CYLINDER)
		return (hit_cylinder(obj->cylinder, ray, t, hit_data));
	return (false);
}

int	is_in_shadow(t_object_list *list,
			t_variation t, t_hit *hit, int skip_id)
{
	t_hit_data		tmp;
	t_object		*obj;
	int				hited;
	double			clos_t;
	t_variation		current_t;

	hited = init_shadow_variables(&clos_t, t);
	obj = list->head;
	while (obj)
	{
		if (obj->id != skip_id)
		{
			set_t_var(&current_t, t, clos_t);
			if (object_hit(obj, hit->ray, current_t, &tmp))
				hited = set_closest_hit(&clos_t, &tmp, hit->hit_data, obj->id);
		}
		obj = obj->next;
	}
	return (hited);
}

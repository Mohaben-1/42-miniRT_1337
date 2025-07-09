/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:45:39 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 16:49:37 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
	t_hit_data *rec)
{
	if (obj->type == OBJ_SPHERE)
		return (hit_sphere(*(obj->sphere), ray, t, rec));
	if (obj->type == OBJ_PLANE)
		return (hit_plane(*(obj->plane), ray, t, rec));
	if (obj->type == OBJ_CYLINDER)
		return (hit_cylinder(obj->cylinder, ray, t, rec));
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

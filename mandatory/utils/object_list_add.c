/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:48:12 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/02 12:11:39 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	object_list_add(t_object_list *list, void *obj, int id, int type)
{
	t_object	*new;

	new = ft_calloc(sizeof(t_object), 1);
	new->type = type;
	new->id = id;
	new->next = list->head;
	if (type == OBJ_SPHERE)
		new->sphere = (t_sphere *)obj;
	else if (type == OBJ_PLANE)
		new->plane = (t_plane *)obj;
	else if (type == OBJ_CYLINDER)
		new->cylinder = (t_cylinder *)obj;
	// else if (type == OBJ_CONE)
	//     new->cone = (t_cone *)obj;
	list->head = new;
}


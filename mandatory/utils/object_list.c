/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:48:12 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 11:55:11 by mohaben-         ###   ########.fr       */
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

void	free_object_list(t_object_list *list)
{
	t_object	*tmp;

	while (list && list->head)
	{
		tmp = list->head;
		list->head = tmp->next;
		if (tmp->type == OBJ_SPHERE)
			free(tmp->sphere);
		else if (tmp->type == OBJ_PLANE)
			free(tmp->plane);
		else if (tmp->type == OBJ_CYLINDER)
			free(tmp->cylinder);
		// else if (tmp->type == OBJ_CONE)
		//     free(tmp->cone);
		free(tmp);
	}
	free(list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_table_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:48:12 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/01 20:48:44 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	hittable_list_add(t_hit_table_list *list, void *obj, int index, int type)
{
	t_hit_table_node	*new;

	new = ft_calloc(sizeof(t_hit_table_node), 1);
	new->type = type;
	new->object = obj;
	new->next = list->head;
	new->index = index;
	list->head = new;
}

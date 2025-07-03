/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:59 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 12:56:35 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	init_rt(t_rt *rt, int fd)
{
	t_object	*tmp;

	create_scene(rt, fd);
	tmp = rt->scene->head;
	while (tmp)
	{
		if (tmp->type == OBJ_SPHERE)
			tmp->sphere->material.ambient = rt->ambient.ratio;
		else if (tmp->type == OBJ_PLANE)
			tmp->plane->material.ambient = rt->ambient.ratio;
		else if (tmp->type == OBJ_CYLINDER)
			tmp->cylinder->material.ambient = rt->ambient.ratio;
		tmp = tmp->next;
	}
}

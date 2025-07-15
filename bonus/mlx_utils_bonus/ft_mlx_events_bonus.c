/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 17:46:08 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	handle_close(void *param)
{
	t_rt		*rt;
	t_object	*current;

	rt = (t_rt *)param;
	current = rt->scene->head;
	while (current)
	{
		if (current->type == OBJ_CONE)
			free_texture(current->cone->material.texture);
		else if (current->type == OBJ_CYLINDER)
			free_texture(current->cylinder->material.texture);
		else if (current->type == OBJ_PLANE)
			free_texture(current->plane->material.texture);
		else if (current->type == OBJ_SPHERE)
			free_texture(current->sphere->material.texture);
		current = current->next;
	}
	free_object_list(rt->scene);
	mlx_delete_image(rt->mlx.ptr, rt->img.img);
	mlx_terminate(rt->mlx.ptr);
	exit(0);
}

void	handle_esc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		handle_close(param);
}

void	ft_mlx_events(t_rt *rt)
{
	mlx_key_hook(rt->mlx.ptr, handle_esc, rt);
	mlx_close_hook(rt->mlx.ptr, handle_close, rt);
	mlx_loop(rt->mlx.ptr);
}

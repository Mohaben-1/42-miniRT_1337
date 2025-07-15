/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 22:18:07 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	handle_close(void *param)
{
	t_rt		*rt;

	rt = (t_rt *)param;
	mlx_delete_image(rt->mlx.ptr, rt->img.img);
	mlx_terminate(rt->mlx.ptr);
	free_object_list(rt->scene);
	ft_putstr_fd("\033[31m👋 Exiting MiniRT... Goodbye!\033[0m\n", 1);
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

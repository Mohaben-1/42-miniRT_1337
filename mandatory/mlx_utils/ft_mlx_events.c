/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:11:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 11:56:00 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	handle_close(t_rt *rt)
{
	mlx_destroy_image(rt->mlx.ptr, rt->img.img);
	mlx_destroy_window(rt->mlx.ptr, rt->mlx.window);
	free_object_list(rt->scene);
	exit(0);
}

int	hande_esc(int keycode, t_rt *rt)
{
	if (keycode == 53)
		handle_close(rt);
	return (0);
}

void	ft_mlx_events(t_rt *rt)
{
	mlx_key_hook(rt->mlx.window, hande_esc, rt);
	mlx_hook(rt->mlx.window, 17, 0, handle_close, rt);
	mlx_loop(rt->mlx.ptr);
	handle_close(rt);
}

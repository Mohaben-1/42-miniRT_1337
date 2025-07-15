/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:22:00 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 22:04:17 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_mlx_init_helper(t_rt *rt)
{
	rt->mlx.ptr = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (!rt->mlx.ptr)
	{
		ft_putstr_fd("Error\nFailed to initialize MLX!\n", 2);
		exit(1);
	}
	rt->img.img = mlx_new_image(rt->mlx.ptr, WIDTH, HEIGHT);
	if (!rt->img.img)
	{
		ft_putstr_fd("Error\nFailed to create image!\n", 2);
		mlx_terminate(rt->mlx.ptr);
		exit(1);
	}
}

void	ft_mlx_init(t_rt *rt)
{
	ft_mlx_init_helper(rt);
	if (mlx_image_to_window(rt->mlx.ptr, rt->img.img, 0, 0) < 0)
	{
		ft_putstr_fd("Error: Failed to put image to window\n", 2);
		mlx_delete_image(rt->mlx.ptr, rt->img.img);
		mlx_terminate(rt->mlx.ptr);
		exit(1);
	}
}

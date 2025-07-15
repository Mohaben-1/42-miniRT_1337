/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:22:00 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 15:33:37 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	ft_mlx_init_helper(t_rt *rt)
{
	rt->mlx.ptr = mlx_init();
	if (!rt->mlx.ptr)
	{
		ft_putstr_fd("Error\nFailed to initialize MLX!\n", 2);
		exit(1);
	}
	rt->mlx.window = mlx_new_window(rt->mlx.ptr, WIDTH, HEIGHT, TITLE);
	if (!rt->mlx.window)
	{
		ft_putstr_fd("Error\nFailed to initialize MLX!\n", 2);
		exit(1);
	}
	rt->img.img = mlx_new_image(rt->mlx.ptr, WIDTH, HEIGHT);
	if (!rt->img.img)
	{
		ft_putstr_fd("Error\nFailed to create image!\n", 2);
		mlx_destroy_window(rt->mlx.ptr, rt->mlx.window);
		exit(1);
	}
}

t_texture	*load_texture(char *path, t_rt *rt)
{
	t_texture	*texture;
	char		*actual_path;

	texture = ft_calloc(1, sizeof(t_texture));
	if (!texture)
		return (NULL);
	actual_path = path + 3;
	texture->path = actual_path;
	texture->img = mlx_xpm_file_to_image(rt->mlx.ptr, actual_path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(actual_path, 2);
		ft_putstr_fd("\n", 2);
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	return (texture);
}

void	ft_mlx_init(t_rt *rt)
{
	ft_mlx_init_helper(rt);
	rt->img.addr = mlx_get_data_addr(rt->img.img, &(rt->img.bpp),
			&(rt->img.line_len), &(rt->img.endian));
	if (!rt->img.addr)
	{
		ft_putstr_fd("Error: Failed to get image data address\n", 2);
		mlx_destroy_image(rt->mlx.ptr, rt->img.img);
		mlx_destroy_window(rt->mlx.ptr, rt->mlx.window);
		exit(1);
	}
}

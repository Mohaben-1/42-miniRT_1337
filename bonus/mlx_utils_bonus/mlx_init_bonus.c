/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:22:00 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 19:09:32 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

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

t_texture	*load_texture(char *path)
{
	t_texture	*texture;
	char		*actual_path;

	texture = ft_calloc(1, sizeof(t_texture));
	if (!texture)
		return (NULL);
	actual_path = path + 5;
	texture->path = actual_path;
	texture->texture = mlx_load_png(actual_path);
	if (!texture->texture)
	{
		ft_putstr_fd("Error\nFailed to load bump map: ", 2);
		ft_putstr_fd(actual_path, 2);
		ft_putstr_fd("\n", 2);
		free(texture);
		return (NULL);
	}
	texture->width = texture->texture->width;
	texture->height = texture->texture->height;
	if (texture->width == 0 || texture->height == 0)
	{
		ft_putstr_fd("Error: Invalid texture dimensions\n", 2);
		return (mlx_delete_texture(texture->texture), free(texture), NULL);
	}
	return (texture);
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

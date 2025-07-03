/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:22:00 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 11:22:29 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void ft_mlx_init_helper(t_rt *rt)
{
  rt->mlx.ptr = mlx_init();
  if (!rt->mlx.ptr)
  {
    ft_putstr_fd("Error\nFailed to initialize MLX!\n", 2);
    exit(EXIT_FAILURE);
  }
  rt->mlx.window = mlx_new_window(rt->mlx.ptr, WIDTH, HEIGHT, "MiniRT (aba hayat khay)");
  if (!rt->mlx.window)
  {
    ft_putstr_fd("Error\nFailed to initialize MLX!\n", 2);
    exit(EXIT_FAILURE);
  }
  rt->img.img = mlx_new_image(rt->mlx.ptr, WIDTH, HEIGHT);
  if (!rt->img.img)
  {
    ft_putstr_fd("Error\nFailed to create image!\n", 2);
    mlx_destroy_window(rt->mlx.ptr, rt->mlx.window);
    exit(EXIT_FAILURE);
  }
}

void ft_mlx_init(t_rt *rt)
{
  ft_mlx_init_helper(rt);
  rt->img.addr = mlx_get_data_addr(rt->img.img, &(rt->img.bpp), &(rt->img.line_len), &(rt->img.endian));
  if (!rt->img.addr)
  {
    ft_putstr_fd("Error: Failed to get image data address\n", 2);
    mlx_destroy_image(rt->mlx.ptr, rt->img.img);
    mlx_destroy_window(rt->mlx.ptr, rt->mlx.window);
    exit(EXIT_FAILURE);
  }
}

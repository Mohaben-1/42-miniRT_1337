/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:45:11 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/06 14:47:14 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	mlx_image_to_window(t_rt *rt, int x, int y)
{
	mlx_put_image_to_window(
		rt->mlx.ptr,
		rt->mlx.window,
		rt->img.img,
		x, y);
}

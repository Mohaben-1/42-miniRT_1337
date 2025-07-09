/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_to_window_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:45:11 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 19:01:55 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	mlx_image_to_window(t_rt *rt, int x, int y)
{
	mlx_put_image_to_window(
		rt->mlx.ptr,
		rt->mlx.window,
		rt->img.img,
		x, y);
}

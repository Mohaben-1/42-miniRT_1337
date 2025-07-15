/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_draw_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:11:26 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/15 17:22:54 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	mlx_pixel_draw(t_img *image, int x, int y, int color)
{
	if (x >= 0 && x < (int)image->img->width && y >= 0 
		&& y < (int)image->img->height)
		mlx_put_pixel(image->img, x, y, color);
}

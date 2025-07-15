/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:11:26 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/15 21:49:06 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	mlx_pixel_draw(t_img *image, int x, int y, int color)
{
	if (x >= 0 && x < (int)image->img->width && y >= 0 
		&& y < (int)image->img->height)
		mlx_put_pixel(image->img, x, y, color);
}

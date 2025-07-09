/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:11:26 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/08 20:36:35 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	mlx_pixel_draw(t_img *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(int *)pixel = color;
}

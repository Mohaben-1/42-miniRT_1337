/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_draw_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:11:26 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 19:02:40 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	mlx_pixel_draw(t_img *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(int *)pixel = color;
}

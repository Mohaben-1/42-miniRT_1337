/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:12:49 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/15 19:54:51 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

uint32_t	color_rgb(t_color *color)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (int)(255.999 * color->r);
	g = (int)(255.999 * color->g);
	b = (int)(255.999 * color->b);
	a = 255;
	return (((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff));
}

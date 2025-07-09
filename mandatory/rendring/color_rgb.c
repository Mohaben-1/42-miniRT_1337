/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:12:49 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/07 12:53:35 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

unsigned long	color_rgb(t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255.999 * color->r);
	g = (int)(255.999 * color->g);
	b = (int)(255.999 * color->b);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

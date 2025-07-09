/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:06:18 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 22:55:40 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	render(t_rt *rt)
{
	if (rt->mlx.window == NULL)
		return (1);
	mlx_clear_window(rt->mlx.ptr, rt->mlx.window);
	render_scene(rt, rt->scene);
	mlx_image_to_window(rt, 0, 0);
	return (0);
}

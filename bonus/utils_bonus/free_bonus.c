/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:45:30 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:56 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	free_dbl_ptr(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_texture(t_texture *texture, t_rt *rt)
{
	if (texture)
	{
		if (texture->img)
			mlx_destroy_image(rt->mlx.ptr, texture->img);
		free(texture);
	}
}

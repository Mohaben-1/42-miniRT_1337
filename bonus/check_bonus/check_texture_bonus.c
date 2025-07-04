/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:12:13 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/04 16:47:07 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_texture(char *texture)
{
	size_t	len;

	if (!texture)
		return (0);
	if (!ft_strncmp(texture, "tx:", 3))
		texture += 3;
	else
	{
		ft_putstr_fd("Error\nInvalid texture identifier: Only 'tx:' is accepted.\n", 2);
		return (0);
	}
	len = ft_strlen(texture);
	if (len < 4 || ft_strncmp(texture + len - 4, ".xpm", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid texture format: Only '.xpm' is supported by MiniLibX.\n", 2);
		return (0);
	}
	if (access(texture, R_OK) != 0)
	{
		ft_putstr_fd("Error\nTexture file not found or unreadable.\n", 2);
		return (0);
	}
	return (1);
}

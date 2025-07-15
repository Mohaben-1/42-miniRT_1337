/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:12:13 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 18:31:41 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_texture(char *texture)
{
	size_t	len;
	char	*path;

	if (!texture)
		return (0);
	if (!ft_strncmp(texture, "bump:", 5))
		path = texture + 5;
	else
	{
		ft_putstr_fd("Error\nInvalid bump map identifier: ", 2);
		return (ft_putstr_fd("Expected 'bump:' prefix.\n", 2), 0);
	}
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".png", 4) != 0)
	{
		ft_putstr_fd("Error\nBump map must be a .png file.\n", 2);
		return (0);
	}
	if (access(path, R_OK) != 0)
	{
		ft_putstr_fd("Error\nTexture file not found or unreadable: ", 2);
		ft_putstr_fd(path, 2);
		return (ft_putstr_fd("\n", 2), 0);
	}
	return (1);
}

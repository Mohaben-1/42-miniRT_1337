/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambient_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:50:05 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 13:31:13 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_ambient(char *line)
{
	char	**splited;

	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 3)
	{
		ft_putstr_fd("Error\nAmbient light requires exactly 2 parameters: ratio and color (e.g. 'A 0.2 255,255,255')\n", 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_ratio(splited[1]))
	{
		ft_putstr_fd("Error\nInvalid ambient light ratio: must be a float between 0.0 and 1.0\n", 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_color(splited[2]))
	{
		ft_putstr_fd("Error\nInvalid ambient light color: expected format 'R,G,B' with values between 0 and 255\n", 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	free_dbl_ptr((void **)splited);
	return (1);
}

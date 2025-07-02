/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:33:14 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/02 20:25:16 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_light_vals(char **splited)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd("Error\nInvalid light position: expected a 3D vector 'x,y,z' with numeric values.\n", 2);
		return (0);
	}
	if (!check_ratio(splited[2]))
	{
		ft_putstr_fd("Error\nInvalid light brightness: expected a float between 0.0 and 1.0.\n", 2);
		return (0);
	}
	if (!check_color(splited[3]))
	{
		ft_putstr_fd("Error\nInvalid light color: expected RGB format 'r,g,b' between 0 and 255.\n", 2);
		return (0);
	}
	return (1);
}

int	check_light(char *line)
{
	char	**splited;

	splited = ft_split(line, ' ');
	if (ft_count_args(splited) != 4)
	{
		ft_putstr_fd("Error\nInvalid light: expected format 'L x,y,z brightness R,G,B'\n", 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_light_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

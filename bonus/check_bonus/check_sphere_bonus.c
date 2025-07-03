/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:42:43 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 13:32:01 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_sphere_vals(char **splited)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd("Error\nInvalid sphere position: expected 'x,y,z' with numeric values.\n", 2);
		return (0);
	}
	if (!check_float(splited[2]))
	{
		ft_putstr_fd("Error\nInvalid sphere diameter: expected a positive floating-point number.\n", 2);
		return (0);
	}
	if (!check_color(splited[3]))
	{
		ft_putstr_fd("Error\nInvalid sphere color: expected RGB format 'r,g,b' between 0 and 255.\n", 2);
		return (0);
	}
	return (1);
}

int	check_sphere(char *line)
{
	char	**splited;

	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 4)
	{
		ft_putstr_fd("Error\nInvalid sphere: expected format 'sp x,y,z diameter r,g,b'\n", 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_sphere_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

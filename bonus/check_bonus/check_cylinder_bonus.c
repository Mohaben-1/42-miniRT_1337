/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:58:37 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 13:31:44 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_cy_vals(char **splited)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd("Error\nInvalid cylinder position: expected 'x,y,z' with numeric values.\n", 2);
		return (0);
	}
	if (!check_normal(splited[2]))
	{
		ft_putstr_fd("Error\nInvalid cylinder axis vector: must be normalized 'x,y,z' between -1 and 1.\n", 2);
		return (0);
	}
	if (!check_float(splited[3]))
	{
		ft_putstr_fd("Error\nInvalid cylinder diameter: expected a positive floating-point number.\n", 2);
		return (0);
	}
	if (!check_float(splited[4]))
	{
		ft_putstr_fd("Error\nInvalid cylinder height: expected a positive floating-point number.\n", 2);
		return (0);
	}
	if (!check_color(splited[5]))
	{
		ft_putstr_fd("Error\nInvalid cylinder color: expected RGB format 'r,g,b' between 0 and 255.\n", 2);
		return (0);
	}
	return (1);
}

int	check_cylinder(char *line)
{
	char	**splited;

	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 6)
	{
		ft_putstr_fd("Error\nInvalid cylinder: expected format 'cy center_x,y,z axis_x,y,z diameter height r,g,b'\n", 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_cy_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

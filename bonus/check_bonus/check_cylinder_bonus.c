/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:58:37 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/05 20:20:39 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_cy_vals(char **splited, int arg_count)
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
	if (arg_count == 7)
	{
		if (ft_strcmp(splited[6], "checker") && !check_texture(splited[6]))
		{
			ft_putstr_fd("Error\nExpected either a '.xpm' bump map texture or 'checker' keyword.\n", 2);
			return (0);
		}
	}
	return (1);
}

int	check_cylinder(char *line)
{
	char	**splited;
	int		arg_count;

	trim_trailing_whitespace_line(line);
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	arg_count = ft_count_args(splited);
	if (arg_count != 6 && arg_count != 7)
	{
		ft_putstr_fd("Error\nInvalid cylinder: expected format 'cy center_x,y,z axis_x,y,z diameter height r,g,b [bump_texture_path or checker]'\n", 2);
		free_dbl_ptr((void **)splited);
		return (0);
	}
	if (!check_cy_vals(splited, arg_count))
	{
		free_dbl_ptr((void **)splited);
		return (0);
	}
	free_dbl_ptr((void **)splited);
	return (1);
}

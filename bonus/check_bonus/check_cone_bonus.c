/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cone_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:09 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/05 20:20:17 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_cone_vals(char **splited, int arg_count)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd("Error\nInvalid cone position: expected format 'x,y,z'.\n", 2);
		return (0);
	}
	if (!check_normal(splited[2]))
	{
		ft_putstr_fd("Error\nInvalid cone axis: must be a normalized vector 'x,y,z'.\n", 2);
		return (0);
	}
	if (!check_float(splited[3]))
	{
		ft_putstr_fd("Error\nInvalid cone height: expected a positive float.\n", 2);
		return (0);
	}
	if (!check_float(splited[4]))
	{
		ft_putstr_fd("Error\nInvalid cone angle: expected a positive float (degrees).\n", 2);
		return (0);
	}
	if (!check_color(splited[5]))
	{
		ft_putstr_fd("Error\nInvalid cone color: expected format 'r,g,b'.\n", 2);
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

int	check_cone(char *line)
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
		ft_putstr_fd("Error\nInvalid cone format: expected 'co pos_x,y,z axis_x,y,z height angle r,g,b [bump_texture_path or checker]'\n", 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_cone_vals(splited, arg_count))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

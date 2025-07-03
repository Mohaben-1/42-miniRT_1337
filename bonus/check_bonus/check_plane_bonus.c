/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:52 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 18:12:00 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_plane_vals(char **splited, int arg_count)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd("Error\nInvalid plane position: expected 'x,y,z' with numeric values.\n", 2);
		return (0);
	}
	if (!check_normal(splited[2]))
	{
		ft_putstr_fd("Error\nInvalid plane normal vector: must be normalized 'x,y,z' between -1 and 1.\n", 2);
		return (0);
	}
	if (!check_color(splited[3]))
	{
		ft_putstr_fd("Error\nInvalid plane color: expected RGB format 'r,g,b' between 0 and 255.\n", 2);
		return (0);
	}
	if (arg_count == 5)
	{
		if (!check_texture(splited[4]))
			return (0);
	}
	return (1);
}

int	check_plane(char *line)
{
	char	**splited;
	int		arg_count;

	trim_trailing_whitespace_line(line);
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	arg_count = ft_count_args(splited);
	if (arg_count != 4 && arg_count != 5)
	{
		ft_putstr_fd("Error\nInvalid plane: expected format 'pl x,y,z normal_x,normal_y,normal_z r,g,b [texture_path]'\n", 2);
		free_dbl_ptr((void **)splited);
		return (0);
	}
	if (!check_plane_vals(splited, arg_count))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

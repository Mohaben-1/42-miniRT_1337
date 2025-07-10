/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:42:43 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/10 19:38:03 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_sphere_vals(char **splited, int arg_count)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd(ERR_POS_S1 ERR_POS_S2, 2);
		return (0);
	}
	if (!check_float(splited[2]))
	{
		ft_putstr_fd(ERR_DIAMETER_S1 ERR_DIAMETER_S2, 2);
		return (0);
	}
	if (!check_color(splited[3]))
	{
		ft_putstr_fd(ERR_COLOR_S1 ERR_COLOR_S2, 2);
		return (0);
	}
	if (arg_count == 5)
	{
		if (ft_strcmp(splited[4], "checker") && !check_texture(splited[4]))
			return (ft_putstr_fd(ERR_BNS1 ERR_BNS2, 2), 0);
	}
	return (1);
}

int	check_sphere(char *line)
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
		ft_putstr_fd(ERR_ARGS_S1 ERR_ARGS_S2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_sphere_vals(splited, arg_count))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:58:37 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/10 19:37:57 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_cy_vals(char **splited, int arg_count)
{
	if (!check_position(splited[1]))
		return (ft_putstr_fd(ERR_POS_CY1 ERR_POS_CY2, 2), 0);
	if (!check_normal(splited[2]))
		return (ft_putstr_fd(ERR_NORMALE_CY1 ERR_NORMALE_CY2, 2), 0);
	if (!check_float(splited[3]))
		return (ft_putstr_fd(ERR_DIAMTR_CY1 ERR_DIAMTR_CY2, 2), 0);
	if (!check_float(splited[4]))
		return (ft_putstr_fd(ERR_HEIGHT_CY1 ERR_HEIGHT_CY2, 2), 0);
	if (!check_color(splited[5]))
		return (ft_putstr_fd(ERR_COLOR_CY1 ERR_COLOR_CY2, 2), 0);
	if (arg_count == 7)
	{
		if (ft_strcmp(splited[6], "checker") && !check_texture(splited[6]))
			return (ft_putstr_fd(ERR_BNS1 ERR_BNS2, 2), 0);
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
		ft_putstr_fd(ERR_ARGS_CY1 ERR_ARGS_CY2 ERR_ARGS_CY3, 2);
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

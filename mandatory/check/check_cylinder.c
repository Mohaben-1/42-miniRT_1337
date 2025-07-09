/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:58:37 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/08 19:37:22 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_cy_vals(char **splited)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd(ERR_POS_CY1 ERR_POS_CY2, 2);
		return (0);
	}
	if (!check_normal(splited[2]))
	{
		ft_putstr_fd(ERR_NORMALE_CY1 ERR_NORMALE_CY2, 2);
		return (0);
	}
	if (!check_float(splited[3]))
	{
		ft_putstr_fd(ERR_DIAMTR_CY1 ERR_DIAMTR_CY2, 2);
		return (0);
	}
	if (!check_float(splited[4]))
	{
		ft_putstr_fd(ERR_HEIGHT_CY1 ERR_HEIGHT_CY2, 2);
		return (0);
	}
	if (!check_color(splited[5]))
		return (ft_putstr_fd(ERR_COLOR_CY1 ERR_COLOR_CY2, 2), 0);
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
		ft_putstr_fd(ERR_ARGS_CY1 ERR_ARGS_CY2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_cy_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

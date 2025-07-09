/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:42:43 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/08 19:48:51 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_sphere_vals(char **splited)
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
		ft_putstr_fd(ERR_ARGS_S1 ERR_ARGS_S2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_sphere_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

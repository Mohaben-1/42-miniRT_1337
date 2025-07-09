/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:33:14 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/08 19:41:19 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_light_vals(char **splited)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd(ERR_POS_L1 ERR_POS_L2, 2);
		return (0);
	}
	if (!check_ratio(splited[2]))
	{
		ft_putstr_fd(ERR_BRIGHT_L1 ERR_BRIGHT_L2, 2);
		return (0);
	}
	if (!check_color(splited[3]))
	{
		ft_putstr_fd(ERR_COLOR_L1 ERR_COLOR_L2, 2);
		return (0);
	}
	return (1);
}

int	check_light(char *line)
{
	char	**splited;

	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 4)
	{
		ft_putstr_fd(ERR_ARGS_L1 ERR_ARGS_L2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_light_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

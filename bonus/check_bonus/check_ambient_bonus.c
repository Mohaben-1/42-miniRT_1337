/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambient_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:50:05 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 11:55:12 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_ambient(char *line)
{
	char	**splited;

	trim_trailing_whitespace_line(line);
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 3)
	{
		ft_putstr_fd(ERR_ARGS_AMBIENT1 ERR_ARGS_AMBIENT2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_ratio(splited[1]))
	{
		ft_putstr_fd(ERR_RATIO_AMBIENT1 ERR_RATIO_AMBIENT2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_color(splited[2]))
	{
		ft_putstr_fd(ERR_COLOR_ABMIENT1 ERR_COLOR_ABMIENT2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	free_dbl_ptr((void **)splited);
	return (1);
}

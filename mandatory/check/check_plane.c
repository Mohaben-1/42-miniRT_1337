/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:52 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/09 18:52:28 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_plane_vals(char **splited)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd(ERR_POS_P1 ERR_POS_P2, 2);
		return (0);
	}
	if (!check_normal(splited[2]))
	{
		ft_putstr_fd(ERR_NORMAL_P1 ERR_NORMAL_P2, 2);
		return (0);
	}
	if (!check_color(splited[3]))
	{
		ft_putstr_fd(ERR_COLOR_P1 ERR_COLOR_P2, 2);
		return (0);
	}
	return (1);
}

int	check_plane(char *line)
{
	char	**splited;

	trim_trailing_whitespace_line(line);
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 4)
	{
		ft_putstr_fd(ERR_ARGS_P1 ERR_ARGS_P2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_plane_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

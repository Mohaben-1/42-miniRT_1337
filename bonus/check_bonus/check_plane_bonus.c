/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:52 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/10 19:38:02 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_plane_vals(char **splited, int arg_count)
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
	if (arg_count == 5)
	{
		if (ft_strcmp(splited[4], "checker") && !check_texture(splited[4]))
			return (ft_putstr_fd(ERR_BNS1 ERR_BNS2, 2), 0);
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
		ft_putstr_fd(ERR_ARGS_P1 ERR_ARGS_P2 ERR_ARGS_P3, 2);
		free_dbl_ptr((void **)splited);
		return (0);
	}
	if (!check_plane_vals(splited, arg_count))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

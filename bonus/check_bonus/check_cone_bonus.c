/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cone_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:09 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/14 15:35:40 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_cone_vals(char **splited, int arg_count)
{
	if (!check_position(splited[1]))
		return (ft_putstr_fd(ERR_POS_CN, 2), 0);
	if (!check_normal(splited[2]))
		return (ft_putstr_fd(ERR_NRM_CN1 ERR_NRM_CN2, 2), 0);
	if (!check_float(splited[3]))
		return (ft_putstr_fd(ERR_H_CN, 2), 0);
	if (!check_float(splited[4]))
		return (ft_putstr_fd(ERR_ANGL_CN1 ERR_ANGL_CN2, 2), 0);
	if (!check_color(splited[5]))
		return (ft_putstr_fd(ERR_CLR_CN, 2), 0);
	if (arg_count == 7)
	{
		if (ft_strcmp(splited[6], "checker") && !check_texture(splited[6]))
			return (ft_putstr_fd(ERR_BNS1 ERR_BNS2, 2), 0);
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
		ft_putstr_fd(ERR_ARGS_CN1 ERR_ARGS_CN2 ERR_ARGS_CN3, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_cone_vals(splited, arg_count))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

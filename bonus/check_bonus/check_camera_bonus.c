/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:40:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/09 20:42:54 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_fov(char *fov)
{
	int	i;

	i = 0;
	while (fov[i] && fov[i] != '\n')
	{
		if (!ft_isdigit(fov[i]))
			return (0);
		i++;
	}
	if (ft_atoi(fov) < 0 || ft_atoi(fov) > 180)
		return (0);
	return (1);
}

int	check_camera_vals(char **splited)
{
	if (!check_position(splited[1]))
	{
		ft_putstr_fd(ERR_POSITION_CAM1 ERR_POSITION_CAM2, 2);
		return (0);
	}
	if (!check_normal(splited[2]))
	{
		ft_putstr_fd(ERR_DIR_CAM1 ERR_D_C2, 2);
		return (0);
	}
	if (!check_fov(splited[3]))
	{
		ft_putstr_fd(ERR_FOV_CAM1 ERR_FOV_CAM2, 2);
		return (0);
	}
	return (1);
}

int	check_camera(char *line)
{
	char	**splited;

	trim_trailing_whitespace_line(line);
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	if (ft_strlen(line) == ft_strlen(splited[0]))
		return (free_dbl_ptr((void **)splited), 0);
	if (ft_count_args(splited) != 4)
	{
		ft_putstr_fd(ERR_ARGS_CAM1 ERR_ARGS_CAM2, 2);
		return (free_dbl_ptr((void **)splited), 0);
	}
	if (!check_camera_vals(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

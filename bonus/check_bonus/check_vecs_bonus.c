/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vecs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:50:40 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/09 22:30:37 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_normal(char *normal)
{
	char	**splited;
	double	val;
	int		i;

	if (!check_commas(normal))
		return (0);
	splited = ft_split(normal, ',');
	if (!splited || ft_count_args(splited) != 3)
		return (free_dbl_ptr((void **)splited), 0);
	i = 0;
	while (i < 3)
	{
		if (!check_double(splited[i]))
			return (free_dbl_ptr((void **)splited), 0);
		val = ft_atof(splited[i]);
		if (val < -1.0 || val > 1.0)
			return (free_dbl_ptr((void **)splited), 0);
		i++;
	}
	free_dbl_ptr((void **)splited);
	return (1);
}

int	is_valid_number(const char *str)
{
	int		i;
	int		dot_count;

	i = 0;
	dot_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1 || !ft_isdigit(str[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_vec(char **vec)
{
	int	i;

	if (!vec || !vec[0] || !vec[1] || !vec[2])
		return (0);
	i = 0;
	while (i < 3)
	{
		if (!is_valid_number(vec[i]) || !check_double(vec[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_position(char *position)
{
	char	**splited;

	if (!check_commas(position))
		return (0);
	splited = ft_split(position, ',');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 3)
		return (free_dbl_ptr((void **)splited), 0);
	if (!check_vec(splited))
		return (free_dbl_ptr((void **)splited), 0);
	free_dbl_ptr((void **)splited);
	return (1);
}

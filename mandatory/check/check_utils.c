/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:56:41 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/09 18:52:38 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_ratio_return(char *line, int has_digit)
{
	double	nb;

	if (!has_digit)
		return (0);
	nb = ft_atof(line);
	if (nb < 0.0 || nb > 1.0)
		return (0);
	return (1);
}

int	check_ratio(char *line)
{
	int	has_digit;
	int	has_dot;
	int	i;

	i = 0;
	if (line[i] == '+' || line[i] == '-')
		i++;
	has_digit = 0;
	has_dot = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			has_digit = 1;
		else if (line[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else
			return (0);
		i++;
	}
	return (check_ratio_return(line, has_digit));
}

int	check_color_val(char *nb)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (nb[i] && nb[i] != '\n')
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	num = ft_atoi(nb);
	if (num < 0 || num > 255)
		return (0);
	return (1);
}

int	check_color(char *line)
{
	char	**splited;
	int		i;

	trim_trailing_whitespace_line(line);
	splited = ft_split(line, ',');
	if (!splited)
		return (0);
	if (ft_count_args(splited) != 3)
		return (free_dbl_ptr((void **)splited), 0);
	i = 0;
	while (splited[i])
	{
		if (!check_color_val(splited[i]))
			return (free_dbl_ptr((void **)splited), 0);
		i++;
	}
	free_dbl_ptr((void **)splited);
	return (1);
}

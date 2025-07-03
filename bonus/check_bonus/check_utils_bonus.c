/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:56:41 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 13:34:32 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_ratio(char *line)
{
	double	nb;
	int		has_digit;
	int		has_dot;
	int		i;

	i = 0;
	if (line[i] == '+' || line[i] == '-')
		i++;
	(has_digit = 0, has_dot = 0);
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
	if (!has_digit)
		return (0);
	nb = ft_atof(line);
	if (nb < 0.0 || nb > 1.0)
		return (0);
	return (1);
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

int	check_commas(char *line)
{
	int	commas;
	int	i;

	i = 0;
	commas = 0;
	while (line[i])
	{
		if (line[i] == ',')
			commas++;
		i++;
	}
	if (commas != 2)
		return (0);
	return (1);
}

int	check_double(char *line)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (line[i] == '-')
		i++;
	while (ft_isdigit(line[i]))
	{
		i++;
		j++;
	}
	if (line[i] == '.')
	{
		i++;
		while (ft_isdigit(line[i]))
		{
			i++;
			j++;
		}
	}
	if (line[i] != '\0' || j == 0)
		return (0);
	return (1);
}

int	check_float(char *line)
{
	int	dot_count;
	int	digit_count;
	int	i;

	i = 0;
	dot_count = 0;
	digit_count = 0;
	if (line[i] == '-')
		return (0);
	if (line[i] == '+')
		i++;
	if (!line[i])
		return (0);
	while (line[i])
	{
		if (line[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (ft_isdigit(line[i]))
			digit_count++;
		else
			return (0);
		i++;
	}
	if (digit_count == 0)
		return (0);
	return (1);
}


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

int check_vec(char **vec)
{
	int i;
	int j;
	int dot_count;

	if (!vec || !vec[0] || !vec[1] || !vec[2])
		return (0);
	i = -1;
	while (++i < 3)
	{
		j = 0;
		dot_count = 0;
		if (vec[i][j] == '-' || vec[i][j] == '+')
			j++;
		if (!vec[i][j])
			return (0);
		while (vec[i][j])
		{
			if (vec[i][j] == '.')
			{
				dot_count++;
				if (dot_count > 1)
					return (0);
				if (!ft_isdigit(vec[i][j+1]))
					return (0);
			}
			else if (!ft_isdigit(vec[i][j]))
				return (0);
			j++;
		}
		if (!check_double(vec[i]))
			return (0);
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

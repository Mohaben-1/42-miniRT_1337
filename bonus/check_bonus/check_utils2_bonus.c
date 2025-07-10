/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:57:27 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/10 19:38:11 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_float_helper(char *line, int i, int dot_count, int digit_count)
{
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
	return (check_float_helper(line, i, dot_count, digit_count));
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

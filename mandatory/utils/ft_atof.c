/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:14:36 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 15:57:09 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	skip_whitespace_and_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static double	parse_integer_part(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	parse_fraction_part(const char *str, int *i)
{
	double	fraction;
	double	result;

	result = 0.0;
	fraction = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			result += (str[*i] - '0') * fraction;
			fraction *= 0.1;
			(*i)++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	i = skip_whitespace_and_sign(str, &sign);
	result = parse_integer_part(str, &i);
	result += parse_fraction_part(str, &i);
	return (result * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:14:36 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/03 12:53:52 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	fraction = 0.1;
	sign = 1;
	i = 0;
	
	// Skip whitespace
	while (ft_isspace(str[i]))
		i++;
	
	// Handle optional sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	
	// Integer part
	while (ft_isdigit(str[i]))
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	
	// Fractional part
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			result += (str[i] - '0') * fraction;
			fraction *= 0.1;
			i++;
		}
	}
	
	return (result * sign);
}

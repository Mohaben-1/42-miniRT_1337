/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:09:41 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/09 18:54:04 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void trim_trailing_whitespace_line(char *line)
{
	int i;

	i = ft_strlen(line) - 1;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\n'))
	{
		line[i] = '\0';
		i--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:23:06 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/03 12:54:48 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	b_read;
	static int	b_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1337)
	{
		if (b_pos >= b_read)
		{
			b_read = read(fd, buffer, BUFFER_SIZE);
			b_pos = 0;
			if (b_read <= 0)
				break ;
		}
		line[i++] = buffer[b_pos++];
		if (buffer[b_pos - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

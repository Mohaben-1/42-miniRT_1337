/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:42 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/03 12:54:24 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

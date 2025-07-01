/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:59:58 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/01 20:01:03 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	if (num != 0 && size > ((size_t) -1) / num)
		return (NULL);
	p = malloc(num * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, num * size);
	return (p);
}

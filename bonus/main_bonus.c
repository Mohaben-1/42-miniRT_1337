/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:38:33 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/14 23:31:47 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/minirt_bonus.h"

void	ff(void)
{
	system("leaks -q miniRT");
}

int	main(int ac, char **av)
{
	t_rt	rt;
	int		fd;

	if (!check_args(ac, av[1]) || !check_file(av[1]))
		return (1);
	ft_bzero(&rt, 1);
	ft_mlx_init(&rt);
	fd = open(av[1], O_RDONLY);
	init_rt(&rt, fd);
	close(fd);
	render(&rt);
	ft_mlx_events(&rt);
	return (0);
}

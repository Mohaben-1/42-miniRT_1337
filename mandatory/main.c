/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:21 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/02 23:16:00 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	main(int ac, char **av)
{
	t_rt			rt;
	int				fd;

	if (!check_args(ac, av[1]) || !check_file(av[1]))
		return (1);
	ft_mlx_init(&rt);
	fd = open(av[1], O_RDONLY);
	init_rt(&rt, fd);
	close(fd);
	render(&rt);
	ft_mlx_events(&rt);
	return (0);
}

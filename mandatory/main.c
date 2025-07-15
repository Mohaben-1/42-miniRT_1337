/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:37:44 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 22:24:34 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	main(int ac, char **av)
{
	t_rt	rt;
	int		fd;

	ft_putstr_fd("\n\033[1;36m===== miniRT - Minimal Ray Tracer", 1);
	ft_putstr_fd(" =====\033[0m\n", 1);
	ft_putstr_fd("🎬 MiniRT: Starting raytracer...\n", 1);
	ft_putstr_fd("📖 Verifying scene file...\n", 1);
	if (!check_args(ac, av[1]) || !check_file(av[1]))
		return (1);
	ft_bzero(&rt, 1);
	ft_mlx_init(&rt);
	fd = open(av[1], O_RDONLY);
	ft_putstr_fd("⚙️  Loading and parsing scene...\n", 1);
	init_rt(&rt, fd);
	close(fd);
	ft_putstr_fd("🎨 Rendering scene... Please wait.\n", 1);
	render(&rt);
	ft_putstr_fd("✅ Scene loaded and ready! Use ESC to exit.\n", 1);
	ft_mlx_events(&rt);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:21 by ahouass           #+#    #+#             */
/*   Updated: 2025/06/17 20:54:33 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	// void	*mlx;
	// void	*mlx_win;
	// void	*mlx_img;
	t_scene	*scene;

	if (ac != 2)
		return 1;
	scene = ft_parse_scene(av[1]);
	if (!scene)
		return 1;
	render_sphere(scene);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:21 by ahouass           #+#    #+#             */
/*   Updated: 2025/06/17 20:27:27 by mohaben-         ###   ########.fr       */
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

	t_camera cam = {{0, 0, 0}, {0, 0, 1}, 90}; // Position (0,0,0), looks forward, 90° FOV
    t_sphere sphere = {{0, 0, 5}, 1.0, {255, 0, 0}}; // Red sphere at (0,0,5), radius=1
    t_light light = {{2, 3, 0}, 1.0}; // Light at (2,3,0), full intensity
    render_sphere(cam, sphere, light, 800, 600); // Render 800x600 image
    return 0;
	return 0;
}

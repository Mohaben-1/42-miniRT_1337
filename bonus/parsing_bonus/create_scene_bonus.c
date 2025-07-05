/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:56:26 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/05 16:43:27 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	parse_line(t_rt *rt, char *line, int *id)
{
	if (ft_strncmp(line, "C", 1) == 0)
		parse_camera(line, &rt->camera);
	else if (ft_strncmp(line, "A", 1) == 0)
		parse_ambient(line, &rt->ambient);
	// else if (ft_strncmp(line, "L", 1) == 0)
	// 	parse_light(line, &rt->lights);
	else if (ft_strncmp(line, "sp", 2) == 0)
		parse_sphere(line, rt->scene, rt, id);
	else if (ft_strncmp(line, "cy", 2) == 0)
		parse_cylinder(line, rt->scene, rt, id);
	else if (ft_strncmp(line, "pl", 2) == 0)
		parse_plane(line, rt->scene, rt, id);
}

void  create_scene(t_rt *rt, int fd)
{
	t_object_list	*scene;
	char					*line;
	int 					id;

	scene = ft_calloc(1, sizeof(t_object_list));
	if (!scene)
	{
		ft_putstr_fd("Error\nMemory allocation failed!\n", 2);
		mlx_destroy_image(rt->mlx.ptr, rt->img.img);
		mlx_destroy_window(rt->mlx.ptr, rt->mlx.window);
		exit(1);
	}
	rt->scene = scene;
	id = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(rt, line, &id);
		free(line);
	}
}

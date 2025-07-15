/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:28:42 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 21:55:31 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_line(t_rt *rt, char *line, int *id)
{
	if (ft_strncmp(line, "C", 1) == 0)
		parse_camera(line, &rt->camera);
	else if (ft_strncmp(line, "A", 1) == 0)
		parse_ambient(line, &rt->ambient);
	else if (ft_strncmp(line, "L", 1) == 0)
		parse_light(line, &rt->light);
	else if (ft_strncmp(line, "sp", 2) == 0)
		parse_sphere(line, rt->scene, rt, id);
	else if (ft_strncmp(line, "cy", 2) == 0)
		parse_cylinder(line, rt->scene, rt, id);
	else if (ft_strncmp(line, "pl", 2) == 0)
		parse_plane(line, rt->scene, rt, id);
}

void	create_scene(t_rt *rt, int fd)
{
	t_object_list	*scene;
	char			*line;
	int				id;

	scene = ft_calloc(1, sizeof(t_object_list));
	if (!scene)
	{
		ft_putstr_fd("Error\nMemory allocation failed!\n", 2);
		mlx_delete_image(rt->mlx.ptr, rt->img.img);
		mlx_terminate(rt->mlx.ptr);
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

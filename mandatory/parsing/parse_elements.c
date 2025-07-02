/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:14:23 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/02 20:28:44 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_color	parse_color(char *input)
{
	char	**splited;
	t_color	color;

	splited = ft_split(input, ',');
	color.r = ft_atof(splited[0]) / 255;
	color.g = ft_atof(splited[1]) / 255;
	color.b = ft_atof(splited[2]) / 255;
	free_dbl_ptr((void **)splited);
	return (color);
}

t_vec	parse_vec(char *input)
{
	char	**splited;
	t_vec	vec;

	splited = ft_split(input, ',');
	vec.x = ft_atof(splited[0]);
	vec.y = ft_atof(splited[1]);
	vec.z = ft_atof(splited[2]);
	free_dbl_ptr((void **)splited);
	return (vec);
}

void	parse_camera(char *input, t_camera *camera)
{
	char	**splited;

	splited = ft_split(input, ' ');
	camera->origin = parse_vec(splited[1]);
	camera->target = parse_vec(splited[2]);
	camera->fov = ft_atof(splited[3]);
	free_dbl_ptr((void **)splited);
}

void	parse_ambient(char *input, t_ambient *ambient)
{
	char	**splited;

	splited = ft_split(input, ' ');
	ambient->ratio = ft_atof(splited[1]);
	ambient->color = parse_color(splited[2]);
	free_dbl_ptr((void **)splited);
}

void	parse_light(char *input, t_light *light)
{
	char	**splited;

	splited = ft_split(input, ' ');
	light->position = parse_vec(splited[1]);
	light->intensity = ft_atof(splited[2]);
	light->color = color_create(1, 1, 1);
	free_dbl_ptr((void **)splited);
}

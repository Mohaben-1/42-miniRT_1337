/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:14:23 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/01 20:07:21 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	parse_color(char *input)
{
	char	**splited;
	t_color	color;

	splited = ft_split(input, ',');
	color.r = ft_atof(splited[0]) / 255;
	color.g = ft_atof(splited[1]) / 255;
	color.b = ft_atof(splited[2]) / 255;
	free_dbl_ptr(splited);
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
	free_dbl_ptr(splited);
	return (vec);
}

void	parse_camera(char *input, t_camera *camera)
{
	char	**splited;

	splited = ft_split(input, ' ');
	camera->origin = parse_vec(splited[1]);
	camera->target = parse_vec(splited[2]);
	camera->fov = ft_atof(splited[3]);
	free_dbl_ptr(splited);
}

void	parse_ambient(char *input, t_ambient *ambient)
{
	char	**splited;

	splited = ft_split(input, ' ');
	ambient->ratio = ft_atof(splited[1]);
	ambient->color = parse_color(splited[2]);
	free_dbl_ptr(splited);
}

void	parse_light(char *input, t_light *light)
{
	char	**splited;

	splited = ft_split(input, ' ');
	light->position = parse_vec(splited[1]);
	light->intensity = ft_atof(splited[2]);
	light->color = vec_create(1, 1, 1);
	free_dbl_ptr(splited);
}

void	parse_sphere(char *input, t_hit_table_list *world, t_rt *rt, int *i)
{
	char		**splited;
	t_sphere	*sphere;

	splited = ft_split(input, ' ');
	sphere = ft_calloc(sizeof(t_sphere), 1);
	sphere->center = parse_vec(splited[1]);
	sphere->radius = atof(splited[2]) / 2;
	sphere->type = SPHERE;
	sphere->material.ambient = rt->ambient;

}


void	parse_sphere(char *input, t_hit_table_list *world, t_rt *rt, int *i)
{
	t_sphere	*sphere;
	char		**split;

	split = ft_split(ln, ' ');
	sphere = ft_calloc(sizeof(t_sphere), 1);
	sphere->center = parse_vector(split[1]);

	sphere->radius = ft_atof(split[2]) / 2;
	sphere->type = SPHERE;
	sphere->m.ambient = minirt->ambient.ratio;
	sphere->m.diffuse = 0.9;
	sphere->m.specular = 0;
	sphere->m.shininess = 200;
	sphere->m.color = parse_color(split[3]);
	ft_free_matrix((void **)split);
	hittable_list_add(world, sphere, *i, SPHERE);
	(*i)++;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:30:16 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/02 12:31:01 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_sphere(char *input, t_object_list *world, t_rt *rt, int *i)
{
	char		**splited;
	t_sphere	*sphere;

	splited = ft_split(input, ' ');
	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->center = parse_vec(splited[1]);
	sphere->radius = atof(splited[2]) / 2;
	sphere->type = OBJ_SPHERE;
	sphere->material.ambient = rt->ambient.ratio;
	sphere->material.diffuse = 0.9;
	sphere->material.specular = 0;
	sphere->material.shininess = 200;
	sphere->material.color = parse_color(splited[3]);
	object_list_add(world, sphere, *i, OBJ_SPHERE);
	free_dbl_ptr(splited);
	(*i)++;
}

void	parse_cylinder(char *input, t_object_list *lst, t_rt *rt, int *i)
{
	char		**splited;
	t_cylinder	*cy;

	splited = ft_split(input, ' ');
	cy = ft_calloc(1, sizeof(t_cylinder));
	cy->center = parse_vec(splited[1]);
	cy->axis = parse_vec(splited[2]);
	cy->radius = ft_atof(splited[3]) / 2;
	cy->height = ft_atof(splited[4]);
	cy->type = OBJ_CYLINDER;
	cy->material.ambient = rt->ambient.ratio;
	cy->material.diffuse = 0.9;
	cy->material.specular = 0;
	cy->material.shininess = 200;
	cy->material.color = parse_color(splited[5]);
	cy->cap_top = vec_add(cy->center, vec_scale(cy->axis, cy->height / 2.0));
	cy->cap_bottom = vec_add(cy->center, vec_scale(cy->axis, -(cy->height / 2.0)));
	object_list_add(lst, cy, *i, OBJ_CYLINDER);
	free_dbl_ptr(splited);
	(*i)++;
}

void	parse_plane(char *input, t_object_list *world, t_rt *rt, int *i)
{
	char	**splited;
	t_plane	*pl;

	splited = ft_split(input, ' ');
	pl = ft_calloc(1, sizeof(t_plane));
	pl->position = parse_vec(splited[1]);
	pl->normal = parse_vec(splited[2]);
	pl->type = OBJ_PLANE;
	pl->material.ambient = rt->ambient.ratio;
	pl->material.diffuse = 0.9;
	pl->material.specular = 0;
	pl->material.shininess = 200;
	pl->material.color = parse_color(splited[3]);
	object_list_add(world, pl, *i, OBJ_PLANE);
	free_dbl_ptr(splited);
	(*i)++;
}

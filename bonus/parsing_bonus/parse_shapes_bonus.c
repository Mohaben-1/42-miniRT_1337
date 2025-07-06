/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:30:16 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/06 16:04:24 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	parse_sphere(char *input, t_object_list *scene, t_rt *rt, int *id)
{
	char		**splited;
	int			arg_count;
	t_sphere	*sphere;

	splited = ft_split(input, ' ');
	arg_count = ft_count_args(splited);
	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->center = parse_vec(splited[1]);
	sphere->radius = atof(splited[2]) / 2;
	sphere->type = OBJ_SPHERE;
	sphere->material.ambient = rt->ambient.ratio;
	sphere->material.diffuse = 0.9;
	sphere->material.specular = 0.4;
	sphere->material.shininess = 200;
	sphere->material.color = parse_color(splited[3]);
	if (arg_count == 5)
	{
		if (!ft_strcmp(splited[4], "checker"))
			sphere->material.texture_type = TEX_CHECKER;
		else
			sphere->material.texture_type = TEX_BUMP;
	}
	else
		sphere->material.texture_type = TEX_NONE;
	object_list_add(scene, sphere, *id, OBJ_SPHERE);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

void	parse_cylinder(char *input, t_object_list *lst, t_rt *rt, int *id)
{
	char		**splited;
	int			arg_count;
	t_cylinder	*cy;

	splited = ft_split(input, ' ');
	arg_count = ft_count_args(splited);
	cy = ft_calloc(1, sizeof(t_cylinder));
	cy->center = parse_vec(splited[1]);
	cy->axis = parse_vec(splited[2]);
	cy->radius = ft_atof(splited[3]) / 2;
	cy->height = ft_atof(splited[4]);
	cy->type = OBJ_CYLINDER;
	cy->cap_top = vec_add(cy->center, vec_scale(cy->axis, cy->height / 2.0));
	cy->cap_bottom = vec_add(cy->center, vec_scale(cy->axis, -(cy->height / 2.0)));
	cy->material.ambient = rt->ambient.ratio;
	cy->material.diffuse = 0.9;
	cy->material.specular = 0.4;
	cy->material.shininess = 200;
	cy->material.color = parse_color(splited[5]);
	if (arg_count == 7)
	{
		if (!ft_strcmp(splited[6], "checker"))
			cy->material.texture_type = TEX_CHECKER;
		else
			cy->material.texture_type = TEX_BUMP;
	}
	else
		cy->material.texture_type = TEX_NONE;
	object_list_add(lst, cy, *id, OBJ_CYLINDER);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

void	parse_plane(char *input, t_object_list *scene, t_rt *rt, int *id)
{
	char	**splited;
	int		arg_count;
	t_plane	*pl;

	splited = ft_split(input, ' ');
	arg_count = ft_count_args(splited);
	pl = ft_calloc(1, sizeof(t_plane));
	pl->position = parse_vec(splited[1]);
	pl->normal = parse_vec(splited[2]);
	pl->type = OBJ_PLANE;
	pl->material.ambient = rt->ambient.ratio;
	pl->material.diffuse = 0.9;
	pl->material.specular = 0.4;
	pl->material.shininess = 200;
	pl->material.color = parse_color(splited[3]);
	if (arg_count == 5)
	{
		if (!ft_strcmp(splited[4], "checker"))
			pl->material.texture_type = TEX_CHECKER;
		else
			pl->material.texture_type = TEX_BUMP;
	}
	else
		pl->material.texture_type = TEX_NONE;
	object_list_add(scene, pl, *id, OBJ_PLANE);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

void	parse_cone(char *input, t_object_list *scene, t_rt *rt, int *id)
{
	char	**splited;
	int		arg_count;
	t_cone	*cone;

	splited = ft_split(input, ' ');
	arg_count = ft_count_args(splited);
	cone = ft_calloc(1, sizeof(t_cone));
	cone->vertex = parse_vec(splited[1]);
	cone->axis = parse_vec(splited[2]);
	cone->angle = ft_atof(splited[3]);
	cone->height = ft_atof(splited[4]);
	cone->type = OBJ_CONE;
	cone->material.ambient = rt->ambient.ratio;
	cone->material.diffuse = 0.9;
	cone->material.specular = 0.4;
	cone->material.shininess = 200;
	cone->material.color = parse_color(splited[5]);
	if (arg_count == 7)
	{
		if (!ft_strcmp(splited[6], "checker"))
			cone->material.texture_type = TEX_CHECKER;
		else
			cone->material.texture_type = TEX_BUMP;
	}
	else
		cone->material.texture_type = TEX_NONE;
	object_list_add(scene, cone, *id, OBJ_CONE);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

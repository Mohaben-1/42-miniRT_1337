/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:30:16 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/14 23:43:34 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

void	set_texture_type(t_sphere *sphere, t_rt *rt, int arg_count, char *str)
{
	if (arg_count == 5)
	{
		if (!ft_strncmp(str, "checker", 7))
			sphere->material.texture_type = TEX_CHECKER;
		else
		{
			sphere->material.texture_type = TEX_BUMP;
			sphere->material.texture = load_texture(str, rt);
		}
	}
	else
		sphere->material.texture_type = TEX_NONE;
}

void	parse_sphere(char *input, t_object_list *scene, t_rt *rt, int *id)
{
	char		**splited;
	int			arg_count;
	t_sphere	*sphere;

	trim_trailing_whitespace_line(input);
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
	sphere->material.texture = NULL;
	set_texture_type(sphere, rt, arg_count, splited[4]);
	object_list_add(scene, sphere, *id, OBJ_SPHERE);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

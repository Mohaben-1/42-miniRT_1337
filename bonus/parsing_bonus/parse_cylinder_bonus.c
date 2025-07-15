/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:30:16 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 17:41:05 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static void	set_texture_type(t_cylinder *cy, int arg_count, char *str)
{
	cy->material.texture = NULL;
	if (arg_count == 7)
	{
		if (!ft_strncmp(str, "checker", 7))
			cy->material.texture_type = TEX_CHECKER;
		else
		{
			cy->material.texture_type = TEX_BUMP;
			cy->material.texture = load_texture(str);
		}
	}
	else
		cy->material.texture_type = TEX_NONE;
}

void	parse_cylinder(char *input, t_object_list *lst, t_rt *rt, int *id)
{
	char		**splited;
	int			arg_count;
	t_cylinder	*cy;

	trim_trailing_whitespace_line(input);
	splited = ft_split(input, ' ');
	arg_count = ft_count_args(splited);
	cy = ft_calloc(1, sizeof(t_cylinder));
	cy->center = parse_vec(splited[1]);
	cy->axis = parse_vec(splited[2]);
	cy->radius = ft_atof(splited[3]) / 2;
	cy->height = ft_atof(splited[4]);
	cy->type = OBJ_CYLINDER;
	cy->cap_top = vec_add(cy->center, vec_scale(cy->axis, cy->height / 2.0));
	cy->cap_bottom = vec_add(cy->center,
			vec_scale(cy->axis, -(cy->height / 2.0)));
	cy->material.ambient = rt->ambient.ratio;
	cy->material.diffuse = 0.9;
	cy->material.specular = 0.4;
	cy->material.shininess = 200;
	cy->material.color = parse_color(splited[5]);
	set_texture_type(cy, arg_count, splited[6]);
	object_list_add(lst, cy, *id, OBJ_CYLINDER);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

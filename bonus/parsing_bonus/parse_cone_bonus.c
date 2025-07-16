/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:30:16 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/16 13:14:05 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static void	set_texture_type(t_cone *cone, int arg_count, char *str)
{
	if (arg_count == 7)
	{
		if (!ft_strncmp(str, "checker", 7))
			cone->material.texture_type = TEX_CHECKER;
		else
		{
			cone->material.texture_type = TEX_BUMP;
			cone->material.texture = load_texture(str);
		}
	}
	else
		cone->material.texture_type = TEX_NONE;
}

void	parse_cone(char *input, t_object_list *scene, t_rt *rt, int *id)
{
	char	**splited;
	int		arg_count;
	t_cone	*cone;

	trim_trailing_whitespace_line(input);
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
	cone->material.texture = NULL;
	set_texture_type(cone, arg_count, splited[6]);
	object_list_add(scene, cone, *id, OBJ_CONE);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

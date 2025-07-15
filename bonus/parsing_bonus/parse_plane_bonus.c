/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:30:16 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/15 10:43:18 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static void	set_texture_type(t_plane *pl, t_rt *rt, int arg_count, char *str)
{
	if (arg_count == 5)
	{
		if (!ft_strncmp(str, "checker", 7))
			pl->material.texture_type = TEX_CHECKER;
		else
		{
			pl->material.texture_type = TEX_BUMP;
			pl->material.texture = load_texture(str, rt);
		}
	}
	else
		pl->material.texture_type = TEX_NONE;
}

void	parse_plane(char *input, t_object_list *scene, t_rt *rt, int *id)
{
	char	**splited;
	int		arg_count;
	t_plane	*pl;

	trim_trailing_whitespace_line(input);
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
	pl->material.texture = NULL;
	set_texture_type(pl, rt, arg_count, splited[4]);
	object_list_add(scene, pl, *id, OBJ_PLANE);
	free_dbl_ptr((void **)splited);
	(*id)++;
}

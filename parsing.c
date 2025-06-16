/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:14:23 by ahouass           #+#    #+#             */
/*   Updated: 2025/06/16 15:49:10 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_free_split(char **split_array)
{
	int	i;

	if (!split_array)
		return;
	
	i = 0;
	while (split_array[i])
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}

void	ft_free_scene(t_scene *scene)
{
	t_object	*obj;
	t_object	*obj_next;
	t_light		*light;
	t_light		*light_next;
	
	if (!scene)
		return;
	
	obj = scene->objects;
	while (obj)
	{
		obj_next = obj->next;
		free(obj);
		obj = obj_next;
	}
	
	light = scene->lights;
	while (light)
	{
		light_next = light->next;
		free(light);
		light = light_next;
	}
	
	free(scene);
}

t_vec3	parse_vector(char *str)
{
	char	**parts;
	t_vec3	vec;
	
	parts = ft_split(str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
	{
		if (parts)
			ft_free_split(parts);
		return ((t_vec3){0, 0, 0});
	}
	
	vec.x = ft_atof(parts[0]);
	vec.y = ft_atof(parts[1]);
	vec.z = ft_atof(parts[2]);
	
	ft_free_split(parts);
	return (vec);
}

t_vec3	parse_normalized_vector(char *str)
{
	t_vec3	vec = parse_vector(str);
	float	len = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	
	if (len == 0)
		return ((t_vec3){0, 0, 0});
	
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

t_vec3	parse_color(char *str)
{
	t_vec3	color;
	char	**parts;
	
	parts = ft_split(str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
	{
		if (parts)
			ft_free_split(parts);
		return ((t_vec3){255, 255, 255});
	}
	
	color.x = ft_atoi(parts[0]);
	color.y = ft_atoi(parts[1]);
	color.z = ft_atoi(parts[2]);
	
	ft_free_split(parts);
	
	// Clamp to [0,255]
	color.x = fmax(0, fmin(255, color.x));
	color.y = fmax(0, fmin(255, color.y));
	color.z = fmax(0, fmin(255, color.z));
	
	return (color);
}

void	add_object(t_scene *scene, t_object obj)
{
	t_object	*new_obj;
	
	new_obj = malloc(sizeof(t_object));
	if (!new_obj)
		return;
	
	*new_obj = obj;
	new_obj->next = scene->objects;
	scene->objects = new_obj;
}

void	parse_sphere(t_scene *scene, char **tokens, int count)
{
	t_object	obj;
	
	if (count != 4)
		return (ft_error("Invalid sphere line"));
	
	obj = (t_object){0};
	obj.type = OBJ_SPHERE;
	obj.data.sphere.center = parse_vector(tokens[1]);
	obj.data.sphere.diameter = ft_atof(tokens[2]);
	obj.data.sphere.color = parse_color(tokens[3]);
	
	if (obj.data.sphere.diameter <= 0)
		return (ft_error("Sphere diameter must be positive"));
	
	add_object(scene, obj);
}

void	parse_plane(t_scene *scene, char **tokens, int count)
{
	t_object	obj;
	
	if (count != 4)
		return (ft_error("Invalid plane line"));
	
	obj = (t_object){0};
	obj.type = OBJ_PLANE;
	obj.data.plane.point = parse_vector(tokens[1]);
	obj.data.plane.normal = parse_normalized_vector(tokens[2]);
	obj.data.plane.color = parse_color(tokens[3]);
	
	add_object(scene, obj);
}

void	parse_cylinder(t_scene *scene, char **tokens, int count)
{
	t_object	obj;
	
	if (count != 6)
		return (ft_error("Invalid cylinder line"));
	
	obj = (t_object){0};
	obj.type = OBJ_CYLINDER;
	obj.data.cylinder.center = parse_vector(tokens[1]);
	obj.data.cylinder.axis = parse_normalized_vector(tokens[2]);
	obj.data.cylinder.diameter = ft_atof(tokens[3]);
	obj.data.cylinder.height = ft_atof(tokens[4]);
	obj.data.cylinder.color = parse_color(tokens[5]);
	
	if (obj.data.cylinder.diameter <= 0 || obj.data.cylinder.height <= 0)
		return (ft_error("Cylinder dimensions must be positive"));
	
	add_object(scene, obj);
}

void	parse_ambient(t_scene *scene, char **tokens, int count)
{
	if (count != 3 || scene->has_ambient)
		return (ft_error("Invalid ambient line"));
	
	scene->ambient.ratio = ft_atof(tokens[1]);
	if (scene->ambient.ratio < 0.0 || scene->ambient.ratio > 1.0)
		return (ft_error("Ambient ratio out of range"));
	
	scene->ambient.color = parse_color(tokens[2]);
	scene->has_ambient = true;
}

void	parse_camera(t_scene *scene, char **tokens, int count)
{
	if (count != 4 || scene->has_camera)
		return (ft_error("Invalid camera line"));
	
	scene->camera.position = parse_vector(tokens[1]);
	scene->camera.orientation = parse_normalized_vector(tokens[2]);
	scene->camera.fov = ft_atof(tokens[3]);
	
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		return (ft_error("Camera FOV out of range"));
	
	scene->has_camera = true;
}

void	parse_light(t_scene *scene, char **tokens, int count)
{
	t_light	*light;
	
	if (count < 3 || count > 4)
		return (ft_error("Invalid light line"));
	
	light = malloc(sizeof(t_light));
	if (!light)
		return (ft_error("Malloc failed"));
	
	light->position = parse_vector(tokens[1]);
	light->brightness = ft_atof(tokens[2]);
	
	if (light->brightness < 0.0 || light->brightness > 1.0)
	{
		free(light);
		return (ft_error("Light brightness out of range"));
	}
	
	if (count == 4)
		light->color = parse_color(tokens[3]);
	else
		light->color = (t_vec3){255, 255, 255};
	
	light->next = scene->lights;
	scene->lights = light;
	scene->has_light = true;
}

void	ft_parse_line(t_scene *scene, char *line)
{
	char	**tokens;
	int		count;

	if (!line || line[0] == '\n' || line[0] == '#')
		return;
	// Remove trailing newline
	line[ft_strlen(line) - 1] = '\0';
	
	tokens = ft_split(line, ' ');
	if (!tokens)
		return;
	
	count = 0;
	while (tokens[count])
		count++;
	
	if (count == 0)
	{
		ft_free_split(tokens);
		return;
	}
	
	if (ft_strcmp(tokens[0], "A") == 0)
		parse_ambient(scene, tokens, count);
	else if (ft_strcmp(tokens[0], "C") == 0)
		parse_camera(scene, tokens, count);
	else if (ft_strcmp(tokens[0], "L") == 0)
		parse_light(scene, tokens, count);
	else if (ft_strcmp(tokens[0], "sp") == 0)
		parse_sphere(scene, tokens, count);
	else if (ft_strcmp(tokens[0], "pl") == 0)
		parse_plane(scene, tokens, count);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		parse_cylinder(scene, tokens, count);
	
	ft_free_split(tokens);
}

t_scene	*ft_parse_scene(char *filename)
{
	int		fd;
	char	*line;
	t_scene	*scene;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	ft_memset(scene, 0, sizeof(t_scene));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		ft_parse_line(scene, line);
		free(line);
	}
	close(fd);
	if (!scene->has_ambient || !scene->has_camera || !scene->has_light)
	{
		printf("camera or light or ambient is missing\n");
		ft_free_scene(scene);
		return (NULL);
	}
	scene->win_width = 1920;
	scene->win_height = 1080;
	return (scene);
}

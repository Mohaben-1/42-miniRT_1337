/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:41:08 by ahouass           #+#    #+#             */
/*   Updated: 2025/06/16 13:36:38 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_vec3(t_vec3 vec, const char *name)
{
	printf("%s: (%.2f, %.2f, %.2f)\n", name, vec.x, vec.y, vec.z);
}

void	print_ambient(t_ambient ambient)
{
	printf("\n=== Ambient Light ===\n");
	printf("Ratio: %.2f\n", ambient.ratio);
	print_vec3(ambient.color, "Color");
}

void	print_camera(t_camera camera)
{
	printf("\n=== Camera ===\n");
	print_vec3(camera.position, "Position");
	print_vec3(camera.orientation, "Orientation");
	printf("FOV: %.2f\n", camera.fov);
}

void	print_light(t_light *light)
{
	printf("\n=== Light ===\n");
	print_vec3(light->position, "Position");
	printf("Brightness: %.2f\n", light->brightness);
	print_vec3(light->color, "Color");
}

void	print_sphere(t_sphere *sphere)
{
	printf("\n=== Sphere ===\n");
	print_vec3(sphere->center, "Center");
	printf("Diameter: %.2f\n", sphere->diameter);
	print_vec3(sphere->color, "Color");
}

void	print_plane(t_plane *plane)
{
	printf("\n=== Plane ===\n");
	print_vec3(plane->point, "Point");
	print_vec3(plane->normal, "Normal");
	print_vec3(plane->color, "Color");
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf("\n=== Cylinder ===\n");
	print_vec3(cylinder->center, "Center");
	print_vec3(cylinder->axis, "Axis");
	printf("Diameter: %.2f\n", cylinder->diameter);
	printf("Height: %.2f\n", cylinder->height);
	print_vec3(cylinder->color, "Color");
}

void	print_scene(t_scene *scene)
{
	t_light		*current_light;
	t_object	*current_obj;

	printf("====== Scene Summary ======\n");
	
	// Print ambient
	if (scene->has_ambient)
		print_ambient(scene->ambient);
	else
		printf("\nNo ambient light defined\n");
	
	// Print camera
	if (scene->has_camera)
		print_camera(scene->camera);
	else
		printf("\nNo camera defined\n");
	
	// Print lights
	if (scene->has_light)
	{
		current_light = scene->lights;
		while (current_light)
		{
			print_light(current_light);
			current_light = current_light->next;
			if (current_light)
				printf("---\n");
		}
	}
	else
		printf("\nNo lights defined\n");
	
	// Print objects
	current_obj = scene->objects;
	if (current_obj)
	{
		printf("\n=== Objects ===\n");
		while (current_obj)
		{
			if (current_obj->type == OBJ_SPHERE)
				print_sphere(&current_obj->data.sphere);
			else if (current_obj->type == OBJ_PLANE)
				print_plane(&current_obj->data.plane);
			else if (current_obj->type == OBJ_CYLINDER)
				print_cylinder(&current_obj->data.cylinder);
			
			current_obj = current_obj->next;
			if (current_obj)
				printf("---\n");
		}
	}
	else
		printf("\nNo objects defined\n");
	
	printf("==========================\n");
}
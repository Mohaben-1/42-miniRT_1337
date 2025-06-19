/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:06:18 by mohaben-          #+#    #+#             */
/*   Updated: 2025/06/19 20:16:37 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3 compute_ray_dir(t_camera cam, int x, int y, int width, int height)
{
	t_vec3	forward = vec_normalize(cam.orientation);
	t_vec3	up = {0, 1, 0};


	if (fabs(vec_dot(forward, up)) > 0.999)
		up = (t_vec3){0, 0, 1};

	t_vec3	right = vec_normalize(vec_cross(forward, up));
	up = vec_cross(right, forward);

	float aspect_ratio = (float)width / height;
	float fov_adjust = tanf(cam.fov * 0.5f * M_PI / 180.0f);

	// Convert screen space to normalized device coordinates (NDC)
	float px = (2 * ((x + 0.5f) / width) - 1) * aspect_ratio * fov_adjust;
	float py = (1 - 2 * ((y + 0.5f) / height)) * fov_adjust;

	t_vec3 dir = vec_add(forward, vec_add(vec_scale(right, px), vec_scale(up, py)));
	return vec_normalize(dir);
}


t_vec3	compute_light(t_vec3 point, t_vec3 normal, t_light light)
{
	t_vec3	light_dir;
	float	total_light;
	float	ambient;
	float	diffuse;

	ambient = 0.1;
	light_dir = vec_normalize(vec_sub(light.position, point));
	diffuse = fmax(0.0, vec_dot(normal, light_dir)) * light.brightness;
	total_light = ambient + diffuse;
	return ((t_vec3){
		total_light * light.color.x,
		total_light * light.color.y,
		total_light * light.color.z
	});
}




int color_to_int(t_vec3 color)
{
	int r;
	int g;
	int b;

	r = (int)(255 * fmin(1.0, fmax(0.0, color.x)));
	g = (int)(255 * fmin(1.0, fmax(0.0, color.y)));
	b = (int)(255 * fmin(1.0, fmax(0.0, color.z)));
	return ((r << 16) | (g << 8) | b);
}

float	hit_sphere(t_vec3 center, float radius, t_vec3 ro, t_vec3 rd)
{
	t_vec3 oc;
	float half_b;
	float c;
	float discriminant;

	oc = vec_sub(ro, center);
	half_b = vec_dot(oc, rd);
	c = vec_dot(oc, oc) - radius * radius;
	discriminant = half_b * half_b - c;
	if (discriminant < 0)
		return (-1.0);
	else
		return (-half_b - sqrt(discriminant));
}

float	hit_plane(t_plane plane, t_vec3 ro, t_vec3 rd)
{
	t_vec3	po_to_ro;
	float	denom;
	float	t;

	denom = vec_dot(plane.normal, rd);
    if (fabs(denom) > 1e-6)
	{
        po_to_ro = vec_sub(plane.point, ro);
        t = vec_dot(po_to_ro, plane.normal) / denom;
        return (t >= 0) ? t : -1.0;
    }
    return -1.0;
}

void render_scene(t_mlx *mlx)
{
	t_scene *scene = mlx->scene;
	int width = scene->win_width;
	int height = scene->win_height;
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			t_vec3 ray_origin = scene->camera.position;
			t_vec3 ray_dir = compute_ray_dir(scene->camera, x, y, width, height);
			float closest_t = INFINITY;
			t_vec3 color = {0, 0, 0}; // Default background color
			t_object *closest_obj = NULL;
			
			// Check intersections with all objects
			t_object *obj = scene->objects;
			while (obj) {
				float t = -1;
				if (obj->type == OBJ_SPHERE) {
					t = hit_sphere(obj->data.sphere.center, obj->data.sphere.diameter / 2, ray_origin, ray_dir);
				}
				// Add plane and cylinder intersection checks here later
				
				if (t > 0 && t < closest_t) {
					closest_t = t;
					closest_obj = obj;
				}
				obj = obj->next;
			}
			
			if (closest_obj) {
				t_vec3 hit_point = vec_add(ray_origin, vec_scale(ray_dir, closest_t));
				t_vec3 normal;
				
				// Calculate normal based on object type
				if (closest_obj->type == OBJ_SPHERE) {
					normal = vec_normalize(vec_sub(hit_point, 
												 closest_obj->data.sphere.center));
				}
				// Add normal calculations for other object types here
				
				// Calculate lighting
				t_light *light = scene->lights;
				while (light) {
					color = vec_add(color, compute_light(hit_point, normal, *light));
					light = light->next;
				}
				
				// Apply ambient light if present
				if (scene->has_ambient) {
					color = vec_add(color, vec_scale(scene->ambient.color, 
												   scene->ambient.ratio));
				}
				
				// Clamp and set pixel color
				my_mlx_pixel_put(&mlx->img, x, y, color_to_int(color));
			} else {
				my_mlx_pixel_put(&mlx->img, x, y, 0x000000); // Black background
			}
		}
	}
}

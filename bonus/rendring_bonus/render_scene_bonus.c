/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:06:18 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/10 16:21:51 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

static double	convert_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

static int	is_vec_equal(t_vec v1, t_vec v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (1);
	return (0);
}

static t_ray	generate_ray(t_camera *camera, t_vec normal)
{
	t_ray		new;

	new.origin = camera->origin;
	new.direction = vec_normalize(vec_sub(
				vec_add(
					vec_add(camera->lower_left_corner,
						vec_scale(camera->horizontal, normal.x)),
					vec_scale(camera->vertical, normal.y)),
				camera->origin));
	return (new);
}

static void	initialize_camera(t_camera *camera, double aspect_ratio)
{
	t_vec	w;
	t_vec	u;
	t_vec	v;
	double	viewport_h;
	double	fov_rad;

	if (is_vec_equal(camera->target, vec_create(0, 1, 0)))
		camera->target.z += 0.0001;
	else if (is_vec_equal(camera->target, vec_create(0, -1, 0)))
		camera->target.z += 0.0001;
	fov_rad = convert_to_radians(camera->fov);
	viewport_h = tan(fov_rad / 2);
	camera->view_up = vec_create(0, 1, 0);
	camera->viewport_height = 1.175 * viewport_h;
	camera->viewport_width = aspect_ratio * camera->viewport_height;
	w = vec_unit(vec_negative(&camera->target));
	u = vec_unit(vec_cross(camera->view_up, w));
	v = vec_cross(u, w);
	camera->horizontal = vec_scale(u, camera->viewport_width);
	camera->vertical = vec_scale(v, camera->viewport_height);
	camera->lower_left_corner = vec_sub(
			vec_sub(
				vec_sub(camera->origin,
					vec_div(vec_negative(&camera->horizontal), 2)),
				vec_div(camera->vertical, 2)), w);
}

void	render_scene(t_rt *rt, t_object_list *scene)
{
	t_vec	normal;
	t_vec	pixel;
	t_ray	ray;
	t_color	color;

	initialize_camera(&rt->camera, WIDTH / HEIGHT);
	pixel.x = 0;
	while (pixel.x < WIDTH)
	{
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			normal.x = (double)pixel.x / (WIDTH - 1);
			normal.y = (double)pixel.y / (HEIGHT - 1);
			ray = generate_ray(&rt->camera, normal);
			color = compute_ray_color(ray, scene, rt->lights);
			mlx_pixel_draw(&rt->img, pixel.x, pixel.y, color_rgb(&color));
			pixel.y++;
		}
		pixel.x++;
	}
}

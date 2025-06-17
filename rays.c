#include "minirt.h"

t_vec3	compute_ray_dir(t_camera cam, int pixel_x, int pixel_y)
{
	t_vec3	ray_dir;
	float	ndc_x;
	float	ndc_y;
	float	aspect_ratio;
	float	fov_adjust;

	ndc_x = (2.0 * pixel_x / SCREEN_WIDTH) - 1.0;
	ndc_y = 1.0 - (2.0 * pixel_y / SCREEN_HEIGHT);
	aspect_ratio = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	ndc_x *= aspect_ratio;
	fov_adjust = tan(cam.fov * 0.5 * M_PI / 180.0);
	ndc_x *= fov_adjust;
	ndc_y *= fov_adjust;
	ray_dir = (t_vec3){ndc_x, ndc_y, 1.0};
	return (vec_normalize(ray_dir));
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

void render_sphere(t_scene *scene)
{
    t_camera cam;
    t_sphere sphere;
    t_light light;
	int		x;
	int		y;

	cam = scene->camera;
    sphere = scene->objects->data.sphere;
    light = *scene->lights;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			t_vec3 ray_dir = compute_ray_dir(cam, x, y);
            t_vec3 oc = vec_sub(cam.position, sphere.center);
            double a = vec_dot(ray_dir, ray_dir);
            double b = 2.0 * vec_dot(oc, ray_dir);
            double c = vec_dot(oc, oc) - (sphere.diameter * sphere.diameter / 4.0);
            double discriminant = b * b - 4 * a * c;
            if (discriminant >= 0)
			{
                double t = (-b - sqrt(discriminant)) / (2.0 * a);
                t_vec3 hit_point = vec_add(cam.position, vec_scale(ray_dir, t));
                t_vec3 normal = vec_normalize(vec_sub(hit_point, sphere.center));
                t_vec3 color = compute_light(hit_point, normal, light);
                draw_pixel(scene, x, y, color); 
            }
			else
                draw_pixel(scene, x, y, (t_vec3){0, 0, 0});
		}
	}
}

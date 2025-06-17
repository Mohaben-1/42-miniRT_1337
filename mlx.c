#include "minirt.h"

void	draw_pixel(t_scene *scene, int x, int y, t_vec3 color)
{
	char	*pixel;
	int		offset;

	int r = (int)fmin(255, fmax(0, color.x * 255));
	int g = (int)fmin(255, fmax(0, color.y * 255));
	int b = (int)fmin(255, fmax(0, color.z * 255));

	offset = (y * scene->line_length) + (x * (scene->bits_per_pixel / 8));
	pixel = scene->img_addr + offset;

	*(unsigned int *)pixel = (r << 16) | (g << 8) | b;
}

void	init_image(t_scene *scene)
{
    scene->img = mlx_new_image(scene->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    scene->img_addr = mlx_get_data_addr(scene->img, &scene->bits_per_pixel, &scene->line_length, &scene->endian);
}

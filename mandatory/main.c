/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:21 by ahouass           #+#    #+#             */
/*   Updated: 2025/06/24 20:42:06 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_texture *texture, int x, int y, int color)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	*(unsigned int*)dst = color;
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx, mlx->img.img);
	mlx_destroy_window(mlx, mlx->win);
	exit(0);
}

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_window(mlx);
	return (0);
}

t_mlx   init_mlx(t_scene *scene)
{
	t_mlx   mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, scene->win_width, scene->win_height, "miniRT");
	mlx.img.width = scene->win_width;
	mlx.img.height = scene->win_height;
	mlx.img.img = mlx_new_image(mlx.mlx, mlx.img.width, mlx.img.height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
									&mlx.img.line_length, &mlx.img.endian);
	mlx.scene = scene;
	return (mlx);
}


int	print_error(char *err)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

void debug_print_scene(t_scene *scene)
{
    printf("Scene:\n");
    printf("Resolution: %dx%d\n", scene->win_width, scene->win_height);
    printf("Camera: pos(%.2f,%.2f,%.2f) dir(%.2f,%.2f,%.2f) fov:%.2f\n",
           scene->camera.position.x, scene->camera.position.y, scene->camera.position.z,
           scene->camera.orientation.x, scene->camera.orientation.y, scene->camera.orientation.z,
           scene->camera.fov);
    
    t_object *obj = scene->objects;
    while (obj) {
        if (obj->type == OBJ_SPHERE)
            printf("Sphere: center(%.2f,%.2f,%.2f) diam:%.2f color(%.2f,%.2f,%.2f)\n",
                   obj->data.sphere.center.x, obj->data.sphere.center.y, obj->data.sphere.center.z,
                   obj->data.sphere.diameter,
                   obj->data.sphere.color.x, obj->data.sphere.color.y, obj->data.sphere.color.z);
        obj = obj->next;
    }
}

void test_render(t_mlx *mlx)
{
    // Draw a simple gradient for testing
    for (int y = 0; y < mlx->img.height; y++) {
        for (int x = 0; x < mlx->img.width; x++) {
            int r = x * 255 / mlx->img.width;
            int g = y * 255 / mlx->img.height;
            int b = 128;
            int color = (r << 16) | (g << 8) | b;
            my_mlx_pixel_put(&mlx->img, x, y, color);
        }
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_scene *scene;
	
	if (ac != 2)
		return (print_error("Usage: ./miniRT scene.rt"), 1);
	scene = ft_parse_scene(av[1]);
	if (!scene)
		return (1);
	mlx = init_mlx(scene);
	render_scene(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, handle_keypress, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

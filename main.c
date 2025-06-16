/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:21 by ahouass           #+#    #+#             */
/*   Updated: 2025/06/16 16:07:25 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_img {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
} t_img;

typedef struct s_mlx {
    void    *mlx;
    void    *win;
    t_img   img;
    t_scene *scene;
} t_mlx;

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

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_scene	*scene;

	if (ac != 2)
		return 1;
	scene = ft_parse_scene(av[1]);
	if (!scene)
		return 1;
	mlx = init_mlx(scene);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_key_hook(mlx.win, handle_keypress, &mlx);
	mlx_loop(&mlx);
	// print_scene(scene);
	return 0;
}

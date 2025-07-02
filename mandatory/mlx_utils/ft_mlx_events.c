
#include "../includes/minirt.h"

void handle_close(t_rt *rt)
{
    mlx_destroy_image(rt->mlx.ptr, rt->img.img);
    mlx_destroy_window(rt->mlx.ptr, rt->mlx.window);
    free(rt->scene);
    exit(0);
}

void ft_mlx_events(t_rt *rt)
{
  mlx_hook(rt->mlx.window, 17, 0, handle_close, rt);
  mlx_loop(rt->mlx.ptr);
  handle_close(rt);
}



#include "../includes/minirt.h"

void init_rt(t_rt *rt, int fd)
{
  t_object *tmp;

  create_scene(&rt, fd);
  rt->ambient = (t_ambient){0};
  rt->light = (t_light){0};
  rt->camera = (t_camera){0};
  tmp = rt->scene->head;
  while (tmp)
  {
    if (tmp->type == OBJ_SPHERE)
      tmp->sphere->material.ambient = rt->ambient.ratio;
    else if (tmp->type == OBJ_PLANE)
      tmp->plane->material.ambient = rt->ambient.ratio;
    else if (tmp->type == OBJ_CYLINDER)
      tmp->cylinder->material.ambient = rt->ambient.ratio;
    tmp = tmp->next;
  }
}

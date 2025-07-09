

#include "../includes_bonus/minirt_bonus.h"

int within_cone_bounds(double height, double root, t_variation t, double cone_height)
{
  return (height >= 0 && height <= cone_height
		&& root >= t.min && root <= t.max);
}

t_quadratic find_quadra_root(t_quadratic quadra)
{
  quadra.root[0] = (-quadra.b - sqrt(quadra.discriminant)) / (2 * quadra.a);
	quadra.root[1] = (-quadra.b + sqrt(quadra.discriminant)) / (2 * quadra.a);
	return (quadra);
}

int any_root_valid(double height[], double root[], t_variation t, double h)
{
  return (within_cone_bounds(height[0], root[0], t, h)
    || within_cone_bounds(height[1], root[1], t, h));
}

void	set_data_hit_cone(t_hit_data *hit_data, double root, t_vec point)
{
	hit_data->t = root;
	hit_data->point = point;
}

t_quadratic	calculate_cone_quadra(t_ray *ray, t_vec origin_vertex, t_cone cone)
{
	t_quadratic	quadra;
	double		k;

	k = tan(cone.angle) * tan(cone.angle);
	quadra.a = vec_dot(ray->direction, ray->direction) - (1 + k) * pow(vec_dot(ray->direction, cone.axis), 2);
	quadra.b = 2 * (vec_dot(ray->direction, origin_vertex) - (1 + k) * vec_dot(ray->direction, cone.axis) * vec_dot(origin_vertex, cone.axis));
	quadra.c = vec_dot(origin_vertex, origin_vertex) - (1 + k) * pow(vec_dot(origin_vertex, cone.axis), 2);
	quadra.discriminant = quadra.b * quadra.b - 4 * quadra.a * quadra.c;
	return (quadra);
}


void	update_cone_hit_data(t_cone cone, t_ray *ray, t_hit_data *hit_data)
{
	t_vec	point_on_axis;

	point_on_axis = vec_add(cone.vertex, vec_scale(cone.axis, vec_dot(vec_sub(hit_data->point, cone.vertex), cone.axis)));
	hit_data->normal = vec_unit(vec_sub(hit_data->point, point_on_axis));
	determine_surface_normal(hit_data, ray, &hit_data->normal);
}

int	hit_cone(t_cone cone, t_ray *ray, t_variation t, t_hit_data *hit_data)
{
	t_vec	origin_vertex;
	double		h[2];
	t_vec	point[2];
	t_quadratic	quadra;

	origin_vertex = vec_sub(ray->origin, cone.vertex);
	quadra = calculate_cone_quadra(ray, origin_vertex, cone);
	if (quadra.discriminant < 0)
		return (0);
	quadra = find_quadra_root(quadra);
	point[0] = ray_at(*ray, quadra.root[0]);
	h[0] = vec_dot(cone.axis, vec_sub(point[0], cone.vertex));
	point[1] = ray_at(*ray, quadra.root[1]);
	h[1] = vec_dot(cone.axis, vec_sub(point[1], cone.vertex));
	if (any_root_valid(h, quadra.root, t, cone.height))
	{
		if (within_cone_bounds(h[0], quadra.root[0], t, cone.height) && (!within_cone_bounds(h[1],
					quadra.root[1], t, cone.height) || quadra.root[0] < quadra.root[1]))
			set_recor(hit_data, quadra.root[0], point[0]);
		else
			set_data_hit_cone(hit_data, quadra.root[1], point[1]);
		update_cone_hit_data(cone, ray, hit_data);
		return (1);
	}
	return (0);
}

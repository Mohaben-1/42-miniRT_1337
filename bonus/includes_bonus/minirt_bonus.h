/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:15:01 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/11 20:46:13 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "structs_bonus.h"
# include "errors_bonus.h"

// Utils
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char	*str);
void			ft_bzero(void *s, size_t n);
int				ft_count_args(char **args);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
double			ft_atof(const char *str);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isspace(char c);
int				ft_empty_str(char *str);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t num, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
void			trim_trailing_whitespace_line(char *line);
void			free_dbl_ptr(void **ptr);


// Parsing
t_color			parse_color(char *input);
t_vec			parse_vec(char *input);
void			parse_camera(char *input, t_camera *camera);
void			parse_ambient(char *input, t_ambient *ambient);
void			parse_light(char *input, t_light_list **lights);
void			parse_sphere(char *input, t_object_list *scene,
					t_rt *rt, int *id);
void			parse_cylinder(char *input, t_object_list *lst,
					t_rt *rt, int *id);
void			parse_plane(char *input, t_object_list *scene,
					t_rt *rt, int *id);
void			parse_cone(char *input, t_object_list *scene,
					t_rt *rt, int *id);
int				check_args(int ac, char *file);
int				check_file(char *file);
int				check_position(char *position);
int 			check_vec(char **vec);
int				check_normal(char *normal);
int				check_float(char *line);
int				check_double(char *line);
int				check_commas(char *line);
int				check_ratio(char *line);
int				check_color(char *line);
int				check_ambient(char *line);
int				check_camera(char *line);
int				check_light(char *line);
int				check_sphere(char *line);
int				check_plane(char *line);
int				check_cylinder(char *line);
int				check_texture(char *texture);
int				check_cone(char *line);
void			object_list_add(t_object_list *list, void *obj,
					int id, int type);
void			free_object_list(t_object_list *list);

// Vector Operations
t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_scale(t_vec v, double s);
double			vec_dot(t_vec a, t_vec b);
double			vec_len(t_vec v);
t_vec			vec_normalize(t_vec v);
t_vec			vec_cross(t_vec a, t_vec b);
t_vec			vec_div(t_vec vec, double value);
t_vec			vec_negative(t_vec *vec);
t_vec			vec_unit(t_vec vector);
double			vec_len_sqd(const t_vec vector);
t_vec			project_onto_plane(t_vec v, t_vec n);
t_vec			vec_product(t_vec u, t_vec v);
t_vec			vec_reflect(t_vec v, t_vec n);
t_color			color_create(double r, double g, double b);
t_vec			vec_create(double x, double y, double z);

// Mlx utils
void			ft_mlx_init(t_rt *rt);
void			ft_mlx_events(t_rt *rt);
void			mlx_image_to_window(t_rt *rt, int x, int y);
void			mlx_pixel_draw(t_img *image, int x, int y, int color);
int				handle_close(t_rt *rt);

// Init scene
void			create_scene(t_rt *rt, int fd);
void			init_rt(t_rt *rt, int fd);

// Render
int				render(t_rt *rt);
void			render_scene(t_rt *rt, t_object_list *scene);
t_vec			ray_at(t_ray ray, double t);
t_color			compute_ray_color(t_ray ray, t_object_list *scene,
					t_light_list *lights);
t_hit			init_hit(t_cylinder *cyl, t_ray *ray, t_variation t,
					t_hit_data *hit_data);
t_quadratic		init_quadra(t_vec ray_dir, t_vec v, double radius);
void			determine_surface_normal(t_hit_data *hit_data, t_ray *ray,
					t_vec *out_normal);
t_color			compute_lighting(t_material m, t_light light, t_hit *hit,
					int in_shadow);
int				set_closest_hit(double *closest, t_hit_data *tmp_hit,
					t_hit_data *closest_hit, int obj_id);
int				is_valid_intersection(double h, double rt, t_hit *hit);
void			set_hit_data(t_hit *hit, double rt, t_vec point);
int				hit_caps(t_cylinder c, t_ray *ray, t_variation t,
					t_hit_data *hit_data);
unsigned long	color_rgb(t_color *color);
int				find_closest_hit(t_object_list *list, t_ray *ray,
					t_variation t, t_hit_data *hit_data);
void			update_hit_data(t_hit_data *hit_data, t_vec hit_point,
					t_vec cap_base, t_vec axis);
int				is_in_shadow(t_object_list *list, t_variation t,
					t_hit *h, int skip_id);
int				check_cap_intersection(t_hit *hit, double t_val,
					t_vec point, int is_bottom);
int				hit_sphere(t_sphere sphere, t_ray *ray, t_variation t,
					t_hit_data *hit_data);
int				hit_plane(t_plane plane, t_ray *ray, t_variation t,
					t_hit_data *hit_data);
int				hit_cylinder(t_cylinder *cyl, t_ray *ray, t_variation t,
					t_hit_data *hit_data);
int				hit_cone(t_cone cone, t_ray *ray, t_variation t, 
					t_hit_data *hit_data);

t_color	apply_checkerboard(t_hit *hit);


#endif
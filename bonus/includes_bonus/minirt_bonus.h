/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:15:01 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/03 18:13:01 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "structs_bonus.h"

# define WIDTH 1900
# define HEIGHT 1100

// Utils
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char	*str);
void	ft_bzero(void *s, size_t n);
int		ft_count_args(char **args);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
double	ft_atof(const char *str);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(char c);
int		ft_empty_str(char *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
void	trim_trailing_whitespace_line(char *line);
void	free_dbl_ptr(void **ptr);


// Parsing
t_color	parse_color(char *input);
t_vec	parse_vec(char *input);
void	parse_camera(char *input, t_camera *camera);
void	parse_ambient(char *input, t_ambient *ambient);
void	parse_light(char *input, t_light *light);
void	parse_sphere(char *input, t_object_list *scene, t_rt *rt, int *id);
void	parse_cylinder(char *input, t_object_list *lst, t_rt *rt, int *id);
void	parse_plane(char *input, t_object_list *scene, t_rt *rt, int *id);

int		check_args(int ac, char *file);
int		check_file(char *file);
int		check_position(char *position);
int 	check_vec(char **vec);
int		check_normal(char *normal);
int		check_float(char *line);
int		check_double(char *line);
int		check_commas(char *line);
int		check_ratio(char *line);
int		check_color(char *line);
int		check_texture(char *texture);
int		check_ambient(char *line);
int		check_camera(char *line);
int		check_light(char *line);
int		check_sphere(char *line);
int		check_plane(char *line);
int		check_cylinder(char *line);
int		check_cone(char *line);


t_color	color_create(double r, double g, double b);
t_vec	vec_create(double x, double y, double z);

// Vector Operations
t_vec	vec_add(t_vec a, t_vec b);
t_vec	vec_sub(t_vec a, t_vec b);
t_vec	vec_scale(t_vec v, double s);
double	vec_dot(t_vec a, t_vec b);
double	vec_len(t_vec v);
t_vec	vec_normalize(t_vec v);
t_vec	vec_cross(t_vec a, t_vec b);

void	object_list_add(t_object_list *list, void *obj, int id, int type);
void	free_object_list(t_object_list *list);

void ft_mlx_init(t_rt *rt);
void ft_mlx_events(t_rt *rt);

void  init_rt(t_rt *rt, int fd);
void  create_scene(t_rt *rt, int fd);




int	handle_close(t_rt *rt);

#endif
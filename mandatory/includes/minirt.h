/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:15:01 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/02 12:45:53 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_H
# define MINIRT_H

# include "structs.h"

# define WIDTH 1900.0
# define HEIGHT 1100.0


void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char	*str);
double	ft_atof(const char *str);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
void	free_dbl_ptr(void **ptr);


// Parsing
t_color	parse_color(char *input);
t_vec	parse_vec(char *input);
void	parse_camera(char *input, t_camera *camera);
void	parse_ambient(char *input, t_ambient *ambient);
void	parse_light(char *input, t_light *light);
void	parse_sphere(char *input, t_object_list *world, t_rt *rt, int *i);
void	parse_cylinder(char *input, t_object_list *lst, t_rt *rt, int *i);
void	parse_plane(char *input, t_object_list *world, t_rt *rt, int *i);


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

#endif
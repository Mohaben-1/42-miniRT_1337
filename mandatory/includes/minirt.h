/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:15:01 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/01 20:48:49 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_H
# define MINIRT_H

# include "structs.h"

# define WIDTH 1900.0
# define HEIGHT 1100.0
# define SPHERE 1
# define PLANE 2
# define PL 2
# define CYLINDER 3
# define CYL 3
# define AMBIENT 0
# define DIFFUSE 1
# define SPECULAR 2
# define RESULT 3

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

t_vec	vec_create(double x, double y, double z);

void	hittable_list_add(t_hit_table_list *list, void *obj, int index, int type);

#endif
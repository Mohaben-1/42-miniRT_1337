/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:50:40 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/03 18:26:34 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

int	check_args(int ac, char *file)
{
	size_t len;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nIncorrect number of arguments - Usage: ./program scene.rt\n", 2);
		return (0);
	}
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 3, ".rt", 3) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension: Expected a file with the '.rt' extension.\n", 2);
		return (0);
	}
	return (1);
}

int	check_required_elements(int fd)
{
	char	*line;
	int		a_count;
	int		c_count;
	int		l_count;

	a_count = 0;
	c_count = 0;
	l_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "A ", 2))
			a_count++;
		else if (!ft_strncmp(line, "C ", 2))
			c_count++;
		else if (!ft_strncmp(line, "L ", 2))
			l_count++;
		free(line);
	}
	close(fd);
	if (a_count != 1 || c_count != 1 || l_count < 1)
	{
		ft_putstr_fd("Error\nScene must contain exactly one Ambient (A), one Camera (C), and at least one Light (L).\n", 2);
		return (0);
	}
	return (1);
}

int	check_valid_line(char *line, int line_num)
{
	int	i;

	i = 0;

	while (line[i])
	{
		if (line[i] == '\r' || line[i] == '\t')
		{
			ft_putstr_fd("Error\nInvalid character found at line: ", 2);
			ft_putnbr_fd(line_num, 2);
			ft_putstr_fd(" please use spaces instead\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int check_line(char *line, int line_num)
{
	if (!check_valid_line(line, line_num))
		return (0);
	if (!ft_strncmp(line, "C ", 2))
		return (check_camera(line));
	else if (!ft_strncmp(line, "A ", 2))
		return (check_ambient(line));
	else if (!ft_strncmp(line, "L ", 2))
		return (check_light(line));
	else if (!ft_strncmp(line, "sp ", 3))
		return (check_sphere(line));
	else if (!ft_strncmp(line, "pl ", 3))
		return (check_plane(line));
	else if (!ft_strncmp(line, "cy ", 3))
		return (check_cylinder(line));
	else if (!ft_strncmp(line, "co ", 3))
		return (check_cone(line));
	else if (!ft_empty_str(line))
	{
		ft_putstr_fd("Error\nInvalid line at line ", 2);
		ft_putnbr_fd(line_num, 2);
		ft_putstr_fd(": '", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("'\n", 2);
		return (0);
	}
	return (1);
}

int	check_file(char *file)
{
	char	*line;
	int 	line_num;
	int		check;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nFailed to open file: file not found or permission denied\n", 2), 0);
	if (!check_required_elements(fd))
		return (0);
	fd = open(file, O_RDONLY);
	check = 1;
	line_num = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!check_line(line, line_num))
			check = 0;
		free(line);
		line_num++;
	}
	close(fd);
	return (check);
}

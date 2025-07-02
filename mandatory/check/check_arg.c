/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:50:40 by mohaben-          #+#    #+#             */
/*   Updated: 2025/07/02 20:26:12 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_args(int ac, char *file)
{
	size_t len;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nIncorrect number of arguments. Usage: ./program scene.rt\n", 2);
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
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'C' || line[0] == 'A' || line[0] == 'L')
			count++;
		free(line);
	}
	close(fd);
	if (count != 3)
	{
		ft_putstr_fd("Error\nScene file must contain exactly one Ambient (A), one Camera (C), and one Light (L) definition.\n", 2);
		return (0);
	}
	return (1);
}

int check_line(char *line, int line_num)
{
	if (line[0] == 'C' && line[1] == ' ')
		return (check_camera(line));
	else if (line[0] == 'A' && line[1] == ' ')
		return (check_ambient(line));
	else if (line[0] == 'L' && line[1] == ' ')
		return (check_light(line));
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		return (check_sphere(line));
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		return (check_plane(line));
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		return (check_cylinder(line));
	else if (!ft_empty_str(line))
	{
		ft_putstr_fd("Error\nInvalid line at line ", 2);
		ft_putnbr_fd(line_num, 2);
		ft_putstr_fd("\n", 2);
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
	return (check);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:21 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/02 20:49:18 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	main(int ac, char **av)
{
	t_object_list	*scene;
	t_rt			rt;
	int				fd;

	if (!check_args(ac, av[1]) || !check_file(av[1]))
		return (1);
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_onto_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medd <medd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:29:34 by ahouass           #+#    #+#             */
/*   Updated: 2025/07/09 22:55:12 by medd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minirt_bonus.h"

t_vec	project_onto_plane(t_vec v, t_vec n)
{
	t_vec		n_scaled;
	double		dot_product;

	dot_product = vec_dot(v, n);
	n_scaled = vec_scale(n, dot_product);
	return (vec_sub(v, n_scaled));
}

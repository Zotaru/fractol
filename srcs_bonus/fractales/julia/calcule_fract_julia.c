/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_fract_julia.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:27:36 by amonier           #+#    #+#             */
/*   Updated: 2023/05/12 00:07:11 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	calcule_fract_julia(t_fpoint *act, float z_re, float z_im)
{
	int	n;
	t_z	z_n;
	t_z	z_n_plus_1;
	t_z	c;

	z_n.real = act->real_x;
	z_n.unreal = act->unreal_yi;
	c.real = z_re;
	c.unreal = z_im;
	n = 0;
	while (n < N_MAX)
	{
		z_n_plus_1.real = (z_n.real * z_n.real) - (z_n.unreal * z_n.unreal)
			+ c.real;
		z_n_plus_1.unreal = 2.0 * z_n.real * z_n.unreal + c.unreal;
		z_n_plus_1.modulus = z_n_plus_1.real * z_n_plus_1.real
			+ z_n_plus_1.unreal * z_n_plus_1.unreal;
		if (z_n_plus_1.modulus > 4.0)
			break ;
		z_n = z_n_plus_1;
		n++;
	}
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_fractole_newton.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:18:03 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 19:36:41 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static float	denominator(t_z z_n)
{
	float	divide;

	divide = (z_n.real * z_n.real * z_n.real * z_n.real) + (2.0 * z_n.real
			* z_n.real * z_n.unreal * z_n.unreal) + (z_n.unreal * z_n.unreal
			* z_n.unreal * z_n.unreal);
	return (divide);
}

static float	real_numerator(t_z z_n)
{
	float	real_num;

	real_num = (2.0 * z_n.real * z_n.real * z_n.real * z_n.real * z_n.real)
		+ (4.0 * z_n.real * z_n.real * z_n.real * z_n.unreal * z_n.unreal)
		+ (2.0 * z_n.real * z_n.unreal * z_n.unreal * z_n.unreal * z_n.unreal)
		+ (z_n.real * z_n.real) - (z_n.unreal * z_n.unreal);
	return (real_num);
}

static float	real_i_numerator(t_z z_n)
{
	float	im_num;

	im_num = (2.0 * z_n.real * z_n.real * z_n.real * z_n.real * z_n.unreal)
		+ (4.0 * z_n.real * z_n.real * z_n.unreal * z_n.unreal * z_n.unreal)
		+ (2.0 * z_n.unreal * z_n.unreal * z_n.unreal * z_n.unreal * z_n.unreal)
		- (2 * z_n.real * z_n.unreal);
	return (im_num);
}

/*
tabf de float:
tabf[3]
tabf[0] = divide
tabf[1] = real_num
tabf[2] = im_num
*/

t_z	calcule_fract_newton(t_fpoint *act)
{
	int		n;
	t_z		z_n;
	t_z		z_n_plus_1;
	float	tabf[3];

	z_n.real = act->real_x;
	z_n.unreal = act->unreal_yi;
	n = 0;
	while (n < N_MAX)
	{
		tabf[0] = denominator(z_n);
		tabf[1] = real_numerator(z_n);
		tabf[2] = real_i_numerator(z_n);
		z_n_plus_1.real = (tabf[1]) / (3.0 * (tabf[0]));
		z_n_plus_1.unreal = (tabf[2]) / (3.0 * (tabf[0]));
		z_n = z_n_plus_1;
		n++;
	}
	return (z_n);
}

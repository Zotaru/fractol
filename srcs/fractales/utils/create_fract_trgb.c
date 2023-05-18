/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fract_trgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:07:17 by amonier           #+#    #+#             */
/*   Updated: 2023/05/10 23:33:36 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_fract_trgb(int n_i)
{
	float	t;
	float	r;
	float	g;
	float	b;
	float	n;

	n = (float)n_i / (float)N_MAX;
	t = 0;
	r = 9.0 * (1.0 - n) * n * n * n * 255.0;
	g = 15.0 * (1.0 - n) * (1.0 - n) * n * n * 255.0;
	b = 8.5 * (1.0 - n) * (1.0 - n) * (1.0 - n) * n * 255.0;
	return ((int)t << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fract_trgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:07:17 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 19:49:29 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	first_switch(float *t, float *r, float *g, float *b)
{
	*t = *r;
	*r = *g;
	*g = *b;
	*b = *t;
	*t = 0;
}

static void	second_switch(float *t, float *r, float *g, float *b)
{
	*t = *b;
	*b = *g;
	*g = *r;
	*r = *t;
	*t = 0;
}

int	create_fract_trgb(int n_i, int color)
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
	if (color == 2)
		first_switch(&t, &r, &g, &b);
	else if (color == 3)
		second_switch(&t, &r, &g, &b);
	return ((int)t << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

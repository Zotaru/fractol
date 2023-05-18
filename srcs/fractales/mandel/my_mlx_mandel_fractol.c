/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_mandel_fractol.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:19:16 by amonier           #+#    #+#             */
/*   Updated: 2023/05/11 00:05:29 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_sym(t_data *img, t_fpoint *point, int n)
{
	int	color;
	int	y2;

	color = create_fract_trgb(n);
	my_mlx_pixel_put(img, (int)point->pixel_x, (int)point->pixel_y, color);
	y2 = IMG_WIDTH - point->pixel_y;
	my_mlx_pixel_put(img, (int)point->pixel_x, y2, color);
}

void	my_mlx_mandel_fractol(t_data *img, t_scale axe)
{
	t_fpoint	act_point;
	float		i;
	float		j;
	int			n;

	i = 0.0;
	j = 0.0;
	while (i < IMG_LENGTH)
	{
		while (j <= IMG_WIDTH / 2)
		{
			act_point.pixel_x = i;
			act_point.pixel_y = j;
			calculate_real_unreal(&act_point, axe);
			n = calcule_fractole_mandel(&act_point);
			if (n < N_MAX)
				fract_sym(img, &act_point, n);
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}

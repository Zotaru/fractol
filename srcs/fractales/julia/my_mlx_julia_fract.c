/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_julia_fract.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:32:08 by amonier           #+#    #+#             */
/*   Updated: 2023/05/10 23:31:10 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_pixel_put(t_data *img, t_fpoint *point, int n)
{
	int	color;

	color = create_fract_trgb(n);
	my_mlx_pixel_put(img, (int)point->pixel_x, (int)point->pixel_y, color);
}

void	my_mlx_julia_fract(t_data *img, float z_re, float z_im, t_scale axe)
{
	t_fpoint	act_point;
	float		i;
	float		j;
	int			n;

	i = 0.0;
	j = 0.0;
	while (i < IMG_LENGTH)
	{
		while (j < IMG_WIDTH)
		{
			act_point.pixel_x = i;
			act_point.pixel_y = j;
			calculate_real_unreal(&act_point, axe);
			n = calcule_fract_julia(&act_point, z_re, z_im);
			if (n < N_MAX)
				julia_pixel_put(img, &act_point, n);
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:36:35 by amonier           #+#    #+#             */
/*   Updated: 2023/05/10 23:11:21 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_zoom(t_vars *mlx, t_data *img, t_scale *axe)
{
	axe->x_min = axe->x_min / 1.01;
	axe->x_max = axe->x_max / 1.01;
	axe->y_min = axe->y_min / 1.01;
	axe->y_max = axe->y_max / 1.01;
	clear_image(img);
	my_mlx_mandel_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return ;
}

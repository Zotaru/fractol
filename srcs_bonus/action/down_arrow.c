/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_arrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:23:12 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 22:20:04 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia_down(t_vars *mlx, t_data *img, t_scale *axe)
{
	float	tmp;

	tmp = axe->y_min;
	axe->y_min -= ((axe->y_max - axe->y_min) * 0.01);
	axe->y_max -= ((axe->y_max - tmp) * 0.01);
	clear_image(img);
	my_mlx_julia_fract(img, mlx->julia_x, mlx->julia_y, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

void	mandel_down(t_vars *mlx, t_data *img, t_scale *axe)
{
	float	tmp;

	tmp = axe->y_min;
	axe->y_min -= ((axe->y_max - axe->y_min) * 0.01);
	axe->y_max -= ((axe->y_max - tmp) * 0.01);
	clear_image(img);
	my_mlx_mandel_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

void	newton_down(t_vars *mlx, t_data *img, t_scale *axe)
{
	float	tmp;

	tmp = axe->y_min;
	axe->y_min -= ((axe->y_max - axe->y_min) * 0.01);
	axe->y_max -= ((axe->y_max - tmp) * 0.01);
	clear_image(img);
	my_mlx_newton_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

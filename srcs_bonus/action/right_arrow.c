/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:17:19 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 22:18:46 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia_right(t_vars *mlx, t_data *img, t_scale *axe)
{
	float	tmp;

	tmp = axe->x_min;
	axe->x_min += ((axe->x_max - axe->x_min) * 0.01);
	axe->x_max += ((axe->x_max - tmp) * 0.01);
	clear_image(img);
	my_mlx_julia_fract(img, mlx->julia_x, mlx->julia_y, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

void	mandel_right(t_vars *mlx, t_data *img, t_scale *axe)
{
	float	tmp;

	tmp = axe->x_min;
	axe->x_min += ((axe->x_max - axe->x_min) * 0.01);
	axe->x_max += ((axe->x_max - tmp) * 0.01);
	clear_image(img);
	my_mlx_mandel_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

void	newton_right(t_vars *mlx, t_data *img, t_scale *axe)
{
	float	tmp;

	tmp = axe->x_min;
	axe->x_min += ((axe->x_max - axe->x_min) * 0.01);
	axe->x_max += ((axe->x_max - tmp) * 0.01);
	clear_image(img);
	my_mlx_newton_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

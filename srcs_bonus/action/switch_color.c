/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:35 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 18:35:37 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mandel_switch(t_vars *mlx, t_data *img, t_scale *axe)
{
	if (axe->color == 1)
		axe->color = 2;
	else if (axe->color == 2)
		axe->color = 3;
	else
		axe->color = 1;
	clear_image(img);
	my_mlx_mandel_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

void	julia_switch(t_vars *mlx, t_data *img, t_scale *axe)
{
	if (axe->color == 1)
		axe->color = 2;
	else if (axe->color == 2)
		axe->color = 3;
	else
		axe->color = 1;
	clear_image(img);
	my_mlx_julia_fract(img, mlx->julia_x, mlx->julia_y, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

void	newton_switch(t_vars *mlx, t_data *img, t_scale *axe)
{
	if (axe->color == 1)
		axe->color = 2;
	else if (axe->color == 2)
		axe->color = 3;
	else
		axe->color = 1;
	clear_image(img);
	my_mlx_newton_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

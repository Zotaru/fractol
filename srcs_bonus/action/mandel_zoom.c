/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:36:35 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 20:27:33 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	temp_axe(t_scale *axe, t_mcaliber mouse, float distance_x,
		float distance_y)
{
	axe->x_min = mouse.x - (distance_x / 3.5);
	axe->x_max = mouse.x + (distance_x / 3.5);
	axe->y_min = mouse.y - (distance_y / 3.5);
	axe->y_max = mouse.y + (distance_y / 3.5);
}

static void	new_axe(t_scale *axe, float *tabf, float vitesseZoom)
{
	axe->x_min = tabf[0] + (axe->x_min - tabf[0]) / vitesseZoom;
	axe->x_max = tabf[1] + (axe->x_max - tabf[1]) / vitesseZoom;
	axe->y_min = tabf[2] + (axe->y_min - tabf[2]) / vitesseZoom;
	axe->y_max = tabf[3] + (axe->y_max - tabf[3]) / vitesseZoom;
}

void	mandel_zoom(t_vars *mlx, t_data *img, t_scale *axe)
{
	t_mcaliber	mouse;
	float		distance_x;
	float		distance_y;
	float		tabf[4];
	float		vitessezoom;

	vitessezoom = 20;
	tabf[0] = axe->x_min;
	tabf[1] = axe->x_max;
	tabf[2] = axe->y_min;
	tabf[3] = axe->y_max;
	mouse.x = (mlx->mouse_x * (axe->x_max - axe->x_min) / IMG_LENGTH)
		+ axe->x_min;
	mouse.y = axe->y_max - (mlx->mouse_y * (axe->y_max - axe->y_min)
			/ IMG_WIDTH);
	distance_x = axe->x_max - axe->x_min;
	distance_y = axe->y_max - axe->y_min;
	temp_axe(axe, mouse, distance_x, distance_y);
	new_axe(axe, tabf, vitessezoom);
	clear_image(img);
	my_mlx_mandel_fractol(img, *axe);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return ;
}

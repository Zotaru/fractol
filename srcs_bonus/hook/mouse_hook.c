/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:21:46 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 18:11:50 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	julia_click(t_vars *mlx, int x, int y)
{
	mlx->julia_x = (x * ((mlx->axe)->x_max - (mlx->axe)->x_min) / IMG_LENGTH)
		+ (mlx->axe)->x_min;
	mlx->julia_y = (mlx->axe)->y_max - (y * ((mlx->axe)->y_max
				- (mlx->axe)->y_min) / IMG_WIDTH);
	clear_image(mlx->img);
	my_mlx_julia_fract(mlx->img, mlx->julia_x, mlx->julia_y, *(mlx->axe));
	mlx_put_image_to_window(mlx->mlx, mlx->win, (mlx->img)->img, 0, 0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *mlx)
{
	mlx_mouse_get_pos(mlx->mlx, mlx->win, &x, &y);
	mlx->mouse_x = x;
	mlx->mouse_y = y;
	if (keycode == 4)
	{
		if (mlx->fract == 1)
			mandel_zoom(mlx, mlx->img, mlx->axe);
		else if (mlx->fract == 2)
			julia_zoom(mlx, mlx->img, mlx->axe);
		else if (mlx->fract == 3)
			newton_zoom(mlx, mlx->img, mlx->axe);
	}
	if (keycode == 5)
	{
		if (mlx->fract == 1)
			mandel_dezoom(mlx, mlx->img, mlx->axe);
		else if (mlx->fract == 2)
			julia_dezoom(mlx, mlx->img, mlx->axe);
		else if (mlx->fract == 3)
			newton_dezoom(mlx, mlx->img, mlx->axe);
	}
	if (keycode == 1 && mlx->fract == 2)
		julia_click(mlx, x, y);
	return (0);
}

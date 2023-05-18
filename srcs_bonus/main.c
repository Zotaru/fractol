/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:39:42 by amonier           #+#    #+#             */
/*   Updated: 2023/05/17 02:21:59 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	init_window(t_vars *mlx, t_data *img)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(1);
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_LENGTH, WINDOW_WIDTH,
			"Fract-ol");
	if (!mlx->win)
		return (free(mlx->mlx), exit(1));
	img->img = mlx_new_image(mlx->mlx, IMG_LENGTH, IMG_WIDTH);
	if (!img->img)
	{
		free(mlx->mlx);
		free(mlx->win);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
	{
		free(img->img);
		free(mlx->mlx);
		free(mlx->win);
		exit(1);
	}
}

static void	create_axe(t_scale *axe)
{
	axe->x_min = -2.0;
	axe->x_max = 2.0;
	axe->y_min = -2.0;
	axe->y_max = 2.0;
	axe->color = 1;
}

int	main(int argc, char **argv)
{
	t_vars	mlx;
	t_data	img;
	t_scale	axe;

	parsing(argc, argv, &mlx);
	create_axe(&axe);
	init_window(&mlx, &img);
	mlx.img = &img;
	mlx.axe = &axe;
	all_hook(&mlx);
	if (mlx.fract == 1)
		my_mlx_mandel_fractol(&img, axe);
	else if (mlx.fract == 2)
		my_mlx_julia_fract(&img, mlx.julia_x, mlx.julia_y, axe);
	else if (mlx.fract == 3)
		my_mlx_newton_fractol(&img, axe);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

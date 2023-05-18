/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_julia_fract.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:32:08 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 18:59:24 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	julia_pixel_put(t_data *img, t_fpoint *point, int n,
		int color_value)
{
	int	color;

	color = create_fract_trgb(n, color_value);
	my_mlx_pixel_put(img, (int)point->pixel_x, (int)point->pixel_y, color);
}

// void	my_mlx_julia_fract(t_data *img, float z_re, float z_im, t_scale axe)
// {
// 	t_fpoint	act_point;
// 	float		i;
// 	float		j;
// 	int			n;

// 	i = 0.0;
// 	j = 0.0;
// 	while (i < IMG_LENGTH)
// 	{
// 		while (j < IMG_WIDTH)
// 		{
// 			act_point.pixel_x = i;
// 			act_point.pixel_y = j;
// 			calculate_real_unreal(&act_point, axe);
// 			n = calcule_fract_julia(&act_point, z_re, z_im);
// 			if (n < N_MAX)
// 				julia_pixel_put(img, &act_point, n, axe.color);
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	return ;
// }

static void	*thread_function(void *arg)
{
	t_thread	*args;
	int			i;
	int			j;
	t_fpoint	act_point;
	int			n;

	args = (t_thread *)arg;
	i = args->start_index;
	j = 0;
	while (i < args->end_index)
	{
		while (j < IMG_WIDTH)
		{
			act_point.pixel_x = i;
			act_point.pixel_y = j;
			calculate_real_unreal(&act_point, args->axe);
			n = calcule_fract_julia(&act_point, args->z_re, args->z_im);
			if (n < N_MAX)
				julia_pixel_put(args->img, &act_point, n, args->axe.color);
			j++;
		}
		i++;
		j = 0;
	}
	pthread_exit(NULL);
}

/*
tableau d int mis ici 
tab[4] donc
tab[0] = i;
tab[1] = index_act
tab[2] = rows_per_thread
tab[3] = rows_remaining
*/

void	my_mlx_julia_fract(t_data *img, float z_re, float z_im, t_scale axe)
{
	pthread_t	threads[NUM_THREADS];
	t_thread	thread_args[NUM_THREADS];
	int			tab[4];

	tab[2] = IMG_LENGTH / NUM_THREADS;
	tab[3] = IMG_LENGTH % NUM_THREADS;
	tab[1] = 0;
	tab[0] = -1;
	while (++tab[0] < NUM_THREADS)
	{
		thread_args[tab[0]].start_index = tab[1];
		thread_args[tab[0]].end_index = tab[1] + tab[2];
		if (tab[0] == NUM_THREADS - 1)
			thread_args[tab[0]].end_index += tab[3];
		tab[1] = thread_args[tab[0]].end_index;
		thread_args[tab[0]].img = img;
		thread_args[tab[0]].z_re = z_re;
		thread_args[tab[0]].z_im = z_im;
		thread_args[tab[0]].axe = axe;
		pthread_create(&threads[tab[0]], NULL, thread_function,
			&thread_args[tab[0]]);
	}
	tab[0] = -1;
	while (++tab[0] < NUM_THREADS)
		pthread_join(threads[tab[0]], NULL);
}

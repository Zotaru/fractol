/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_newton_fractol.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:50:27 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 19:40:48 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// formule:
// f(z) = z - (g(z) / g'(z))
//
//  g(z) = z^3 - 1, les racines sont :
// Racine 1 : r1 = 1
// Racine 2 : r2 = -0.5 + 0.866i
// Racine 3 : r3 = -0.5 - 0.866i
// distance = |z - r|

/*
	tableau de float cree: 
	tabf[3]

	tabf[0] = d1
	tabf[1] = d2
	tabf[2] = d3
*/

static int	color_choose(float *tabf, int color_switch)
{
	if (tabf[0] < tabf[1] && tabf[0] < tabf[2] && color_switch == 1)
		return (0x00FF0000);
	else if (tabf[1] < tabf[0] && tabf[1] < tabf[2] && color_switch == 1)
		return (0x0000FF00);
	else if (tabf[2] < tabf[0] && tabf[2] < tabf[1] && color_switch == 1)
		return (0x000000FF);
	else if (tabf[0] < tabf[1] && tabf[0] < tabf[2] && color_switch == 2)
		return (0x000000FF);
	else if (tabf[1] < tabf[0] && tabf[1] < tabf[2] && color_switch == 2)
		return (0x00FF0000);
	else if (tabf[2] < tabf[0] && tabf[2] < tabf[1] && color_switch == 2)
		return (0x0000FF00);
	else if (tabf[0] < tabf[1] && tabf[0] < tabf[2] && color_switch == 3)
		return (0x0000FF00);
	else if (tabf[1] < tabf[0] && tabf[1] < tabf[2] && color_switch == 3)
		return (0x000000FF);
	else if (tabf[2] < tabf[0] && tabf[2] < tabf[1] && color_switch == 3)
		return (0x00FF0000);
	return (0);
}

int	create_newton_color(t_z *z_n, int color_switch)
{
	float	tabf[3];

	tabf[0] = sqrt((z_n->real - 1) * (z_n->real - 1) + z_n->unreal
			* z_n->unreal);
	tabf[1] = sqrt((z_n->real + 0.5) * (z_n->real + 0.5) + (z_n->unreal - 0.866)
			* (z_n->unreal - 0.866));
	tabf[2] = sqrt((z_n->real + 0.5) * (z_n->real + 0.5) + (z_n->unreal + 0.866)
			* (z_n->unreal + 0.866));
	return (color_choose(tabf, color_switch));
}

void	fract_newton(t_data *img, t_fpoint *point, t_z *z_n, int switch_color)
{
	int	color;

	color = create_newton_color(z_n, switch_color);
	my_mlx_pixel_put(img, (int)point->pixel_x, (int)point->pixel_y, color);
}

// t_z	calcule_fract_newton(t_fpoint *act)
// {
// 	int		n;
// 	t_z		z_n;
// 	t_z		z_n_plus_1;
// 	float	divide;
// 	float	real_num;
// 	float	im_num;

// 	z_n.real = act->real_x;
// 	z_n.unreal = act->unreal_yi;
// 	n = 0;
// 	while (n < N_MAX)
// 	{
// 		divide = (z_n.real * z_n.real * z_n.real * z_n.real) + (2.0 * z_n.real
// 				* z_n.real * z_n.unreal * z_n.unreal) + (z_n.unreal * z_n.unreal
// 				* z_n.unreal * z_n.unreal);
// 		real_num = (2.0 * z_n.real * z_n.real * z_n.real * z_n.real * z_n.real)
// 			+ (4.0 * z_n.real * z_n.real * z_n.real * z_n.unreal * z_n.unreal)
// 			+ (2.0 * z_n.real * z_n.unreal * z_n.unreal * z_n.unreal
// 				* z_n.unreal) + (z_n.real * z_n.real) - (z_n.unreal
// 				* z_n.unreal);
// 		im_num = (2.0 * z_n.real * z_n.real * z_n.real * z_n.real * z_n.unreal)
// 			+ (4.0 * z_n.real * z_n.real * z_n.unreal * z_n.unreal * z_n.unreal)
// 			+ (2.0 * z_n.unreal * z_n.unreal * z_n.unreal * z_n.unreal
// 				* z_n.unreal) - (2 * z_n.real * z_n.unreal);
// 		z_n_plus_1.real = (real_num) / (3.0 * (divide));
// 		z_n_plus_1.unreal = (im_num) / (3.0 * (divide));
// 		z_n = z_n_plus_1;
// 		n++;
// 	}
// 	return (z_n);
// }

// void    my_mlx_newton_fractol(t_data *img, t_scale axe)
// {
//    t_fpoint	act_point;
//    float	i;
//    float	j;
//    t_z		z_final;

//    i = 0.0;

//    while (i < IMG_LENGTH)
//    {
// 		j = 0.0;
// 		while (j < IMG_WIDTH)
// 		{
// 			act_point.pixel_x = i;
// 			act_point.pixel_y = j;
// 			calculate_real_unreal(&act_point, axe);
// 			// faire calcule recurence
// 			z_final = calcule_fract_newton(&act_point);
// 			// color en fonction des racines
// 			fract_newton(img, &act_point, &z_final, axe.color);
// 			j++;
// 		}
// 		i++;
//    }
//    return ;
// }

static void	*thread_function(void *arg)
{
	t_thread	*args;
	float		i;
	float		j;
	t_fpoint	act_point;
	t_z			z_final;

	args = (t_thread *)arg;
	i = args->start_index;
	while (i < args->end_index)
	{
		j = 0.0;
		while (j < IMG_WIDTH)
		{
			act_point.pixel_x = i;
			act_point.pixel_y = j;
			calculate_real_unreal(&act_point, args->axe);
			z_final = calcule_fract_newton(&act_point);
			fract_newton(args->img, &act_point, &z_final, args->axe.color);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

/*
tab d int ici: 
	tab[0] = i
	tab[1] = index_act
	tab[2] = rows_per_thread
	tab[3] = rows_remaining
*/

void	my_mlx_newton_fractol(t_data *img, t_scale axe)
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
		thread_args[tab[0]].axe = axe;
		pthread_create(&threads[tab[0]], NULL, thread_function,
			&thread_args[tab[0]]);
	}
	tab[0] = -1;
	while (++tab[0] < NUM_THREADS)
		pthread_join(threads[tab[0]], NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:18:43 by amonier           #+#    #+#             */
/*   Updated: 2023/05/10 21:33:35 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	esc(int keycode, t_vars *param)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(param->mlx, (param->img)->img);
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:24:51 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 18:46:20 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	left(t_vars *param)
{
	if (param->fract == 1)
		mandel_left(param, param->img, param->axe);
	else if (param->fract == 2)
		julia_left(param, param->img, param->axe);
	else if (param->fract == 3)
		newton_left(param, param->img, param->axe);
}

static void	right(t_vars *param)
{
	if (param->fract == 1)
		mandel_right(param, param->img, param->axe);
	else if (param->fract == 2)
		julia_right(param, param->img, param->axe);
	else if (param->fract == 3)
		newton_right(param, param->img, param->axe);
}

static void	top(t_vars *param)
{
	if (param->fract == 1)
		mandel_top(param, param->img, param->axe);
	else if (param->fract == 2)
		julia_top(param, param->img, param->axe);
	else if (param->fract == 3)
		newton_top(param, param->img, param->axe);
}

static void	down(t_vars *param)
{
	if (param->fract == 1)
		mandel_down(param, param->img, param->axe);
	else if (param->fract == 2)
		julia_down(param, param->img, param->axe);
	else if (param->fract == 3)
		newton_down(param, param->img, param->axe);
}

int	keyboard(int keycode, t_vars *param)
{
	if (keycode == 65361)
		left(param);
	else if (keycode == 65362)
		top(param);
	else if (keycode == 65363)
		right(param);
	else if (keycode == 65364)
		down(param);
	else if (keycode == 65307)
		cross(param);
	else if (keycode == 115)
	{
		if (param->fract == 1)
			mandel_switch(param, param->img, param->axe);
		else if (param->fract == 2)
			julia_switch(param, param->img, param->axe);
		else if (param->fract == 3)
			newton_switch(param, param->img, param->axe);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:13:43 by amonier           #+#    #+#             */
/*   Updated: 2023/05/10 23:05:56 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	all_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, esc, vars);
	mlx_hook(vars->win, 17, 1L << 17, cross, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
}

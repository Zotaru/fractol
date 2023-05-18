/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:09:55 by amonier           #+#    #+#             */
/*   Updated: 2023/05/17 03:05:09 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parsing(int argc, char **argv, t_vars *mlx)
{
	if (argc <= 1 || argc >= 5 || argc == 3 || ft_strlen(argv[1]) < 6)
		bad_command();
	else if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "Mandel", ft_strlen(argv[1])))
			mlx->fract = 1;
		else if (!ft_strncmp(argv[1], "Julias", ft_strlen(argv[1])))
		{
			mlx->fract = 2;
			mlx->julia_x = -0.54;
			mlx->julia_y = 0.54;
		}
		else
			bad_command();
	}
	else if (argc == 4)
	{
		if (ft_strncmp(argv[1], "Julias", ft_strlen(argv[1])))
			bad_command();
		mlx->fract = 2;
		mlx->julia_x = ft_atof(argv[2]);
		mlx->julia_y = ft_atof(argv[3]);
	}
	return ;
}

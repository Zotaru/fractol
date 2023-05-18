/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_fractole_mandel.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:15:11 by amonier           #+#    #+#             */
/*   Updated: 2023/05/10 22:24:26 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	maintenant calcule imaginaire
	donc mandelbrot par point c est: 
	z n+1 = (z n)^2 + c ;
	c etant le complexe que nous avons deja 
	si |z| > 2 pas afficher
	ce sera basique pour un debut mais apres c est good
	
	debut faire la modulus fonction
*/

// j enleve le sqrt pour que ce soit plus simple
// donc c est mudule > 4 et non plus a 2
// void	modulus(t_z *complexe)
// {
// 	complexe->modulus = (complexe->real * complexe->real) + (complexe->unreal
// * complexe->unreal);
// 	return ;
// }

/*
	z n+1 = (z n)^2 + c ;
	100 iteration
	on commence a z = 0 + 0i;
	et on commence a iteration 0
	donc n = 0;
*/

int	calcule_fractole_mandel(t_fpoint *act_point)
{
	int	n;
	t_z	z_n;
	t_z	z_n_plus_1;

	z_n.real = 0;
	z_n.unreal = 0;
	n = 0;
	while (n < N_MAX)
	{
		z_n_plus_1.real = (z_n.real * z_n.real) - (z_n.unreal * z_n.unreal)
			+ act_point->real_x;
		z_n_plus_1.unreal = 2.0 * z_n.real * z_n.unreal + act_point->unreal_yi;
		z_n_plus_1.modulus = z_n_plus_1.real * z_n_plus_1.real
			+ z_n_plus_1.unreal * z_n_plus_1.unreal;
		if (z_n_plus_1.modulus > 4.0)
			break ;
		z_n = z_n_plus_1;
		n++;
	}
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_real_unreal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:02:48 by amonier           #+#    #+#             */
/*   Updated: 2023/05/12 00:07:59 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// remise a l ecchelle:
/*
	va de - 2 a 2 pour les reels
	donc 
	real_x = min_real + (x * pixel_size)

	va de -2i a 2i pour irreel
	donc
	unreal_x = Imax - (y * pixel_size)

	---------------------- pour x ---------------------
	car deja spour transferer de 
	0----------------->1920
	a 
	0----------------->4

	4 la nouvlle longueur
	et 1980 l ancienne juste un produit en croix 
	
	calcul: x_new = x * new_max / ancien_max
	donc x_new = x * 4/ 1920

	ensuite on decale le 0
	x_veritable = x_new - 2
	
	la on a notre -2 a 2 reeel  

	---------------------- pour y ---------------------
	pareil on veut passer a -2i 2i 
	a sachant que de haut en bas on fait de 0 a 1080
	meme manipulation
	y_new = y * 4 / 1920 
	y_veritable = y_new - 2
	maintenant il faut multiplier par -1 pout inverser
	donc y_veritable final = (-1)*y_veritable 
*/

void	calculate_real_unreal(t_fpoint *act_point, t_scale axe)
{
	act_point->real_x = (act_point->pixel_x * (axe.x_max - axe.x_min)
			/ IMG_LENGTH) + axe.x_min;
	act_point->unreal_yi = axe.y_max - (act_point->pixel_y * (axe.y_max
				- axe.y_min) / IMG_WIDTH);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:28:56 by amonier           #+#    #+#             */
/*   Updated: 2023/05/17 02:57:09 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	bad_command(void)
{
	ft_printf("Les differentes commandes sont:\n");
	ft_printf("Mandel");
	ft_printf("\n");
	ft_printf("Julias");
	ft_printf("\n");
	ft_printf("Julias X.XXX X.XXX");
	ft_printf("\n");
	ft_printf("Newton\n");
	exit(1);
}

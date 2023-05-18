/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:32:53 by amonier           #+#    #+#             */
/*   Updated: 2023/05/10 19:33:35 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_str(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		{
			if (str[i] == '.')
				point++;
		}
		else
			bad_command();
		i++;
	}
	if (point == 0 || point >= 2)
		bad_command();
}

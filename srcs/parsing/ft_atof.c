/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:35:14 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 17:45:05 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	atoi_calculus(float *res, char c, int *i)
{
	*res = 10 * (*res) + (float)(c - '0');
	(*i)++;
	return ;
}

static void	float_calculus(float *res, char c, int *i, float *fraction)
{
	*res = *res + ((float)(c - '0')) * (*fraction);
	(*fraction) = (*fraction) * 0.1;
	(*i)++;
}

float	ft_atof(char *str)
{
	float	result;
	float	sign;
	float	fraction;
	int		i;

	fraction = 0.1;
	i = 0;
	result = 0.0;
	sign = 1.0;
	check_str(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		atoi_calculus(&result, str[i], &i);
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		float_calculus(&result, str[i], &i, &fraction);
	return (result * sign);
}

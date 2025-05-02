/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:25:24 by mayoucha          #+#    #+#             */
/*   Updated: 2025/04/28 20:25:26 by mayoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel(t_fractol *f, int x, int y, int color)
{
    int offset = (y * f->line_length + x * (f->bits_per_pixel / 8));
    *(int *)(f->addr + offset) = color;
}

int get_color(int iteration)
{
    if (iteration == MAX_ITER)
        return (0x000000); // Noir si appartient à l'ensemble
    return (0xE5CCFF * iteration / MAX_ITER); // Dégradé
}

double	ft_atof(const char *nptr)
{
	double	sign;
	double	nb;
	double	tmp;
	double	div;

	sign = 1.0;
	tmp = 0.0;
	nb = 0;
	div = 1.0;
	while ((*nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr != '.')
	{
		nb = (nb * 10.0) + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
		{
			nptr++;
			while (*nptr >= '0' && *nptr <= '9')
			{
				tmp = ((tmp * 10.0) + (*nptr - '0'));
				div *= 10.0;
				nptr++;
			}
		}
	return (sign * (nb + tmp / div));
}


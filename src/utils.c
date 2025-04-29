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
    return (0x00FF00 * iteration / MAX_ITER); // Dégradé vert
}



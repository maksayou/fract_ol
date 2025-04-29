/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:25:43 by mayoucha          #+#    #+#             */
/*   Updated: 2025/04/28 20:25:44 by mayoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractal(t_fractol *f)
{
    if (f->type == MANDELBROT)
        draw_mandelbrot(f);
    else if (f->type == JULIA)
        draw_julia(f);
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

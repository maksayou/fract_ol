/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:25:08 by mayoucha          #+#    #+#             */
/*   Updated: 2025/04/28 20:25:10 by mayoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol *f;

    if (argc < 2)
    {
        write(1, "Choisir : ./fractol mandelbrot | julia [re im]\n", 47);
        return (1);
    }
    f = init_fractol(argv);
    if (!f)
        return (1);
    draw_fractal(f);
    setup_hooks(f);
    mlx_loop(f->mlx);
    return (0);
}



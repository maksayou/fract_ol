/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:24:57 by mayoucha          #+#    #+#             */
/*   Updated: 2025/04/28 20:24:59 by mayoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 800

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		min_re, max_re, min_im, max_im;
}				t_fractol;

//MAIN
void	start_fractol(char *type);

//UTILS
void	put_pixel(t_fractol *f, int x, int y, int color);
int	get_color(int iteration);

//MANDELBROT
void	draw_mandelbrot(t_fractol *f);




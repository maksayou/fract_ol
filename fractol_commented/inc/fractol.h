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
#include "libft.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 800

typedef enum e_type
{
    MANDELBROT,
    JULIA
} t_type;

typedef struct s_fractol
{
	void	*mlx;  //ptr to initializing function
	void	*win;  //ptr to window
	void	*img;  //ptr to image on which we will buffer our pixels
	char	*addr; //ptr to function that will add our pixels to image
    t_type  type;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		min_re, max_re, min_im, max_im;
    double      julia_re, julia_im;
}				t_fractol;

typedef struct s_complex
{
    double re;
    double im;
} t_complex;

typedef struct s_fractal
{
    int x;
    int y;
    int iteration;
    t_complex c;
    t_complex z;
    double tmp;
} t_fractale;


//MAIN
void	start_fractol(char *type);

//UTILS
void	put_pixel(t_fractol *f, int x, int y, int color);
int	get_color(int iteration);
void draw_fractal(t_fractol *f);
double	ft_atof(const char *nptr);

//EVENTS
int close_program(t_fractol *f);
void setup_hooks(t_fractol *f);
int handle_key(int keycode, t_fractol *f);
int handle_mouse(int button, int x, int y, t_fractol *f);

//ENSEMBLES
void	draw_mandelbrot(t_fractol *f);
void	draw_julia(t_fractol *f);

// INIT
t_fractol *init_fractol(char **argv);
t_fractol *fractol_init_base(void);
void fractol_init_view(t_fractol *f);
void fractol_parse_args(t_fractol *f, char **argv);

#endif
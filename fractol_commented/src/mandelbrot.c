#include "fractol.h"

void draw_mandelbrot(t_fractol *f)
{
    t_fractale nb;

    nb.y = -1;
    while (++nb.y < HEIGHT)
    {
        nb.x = -1;
        while (++nb.x < WIDTH)
        {
            nb.c.re = f->min_re + nb.x * (f->max_re - f->min_re) / WIDTH;
            nb.c.im = f->min_im + nb.y * (f->max_im - f->min_im) / HEIGHT;
            nb.z.re = 0;
            nb.z.im = 0;
            nb.iteration = 0;
            while (nb.z.re * nb.z.re + nb.z.im * nb.z.im <= 4 && nb.iteration < MAX_ITER)
            {
                nb.tmp = nb.z.re * nb.z.re - nb.z.im * nb.z.im + nb.c.re;
                nb.z.im = 2 * nb.z.re * nb.z.im + nb.c.im;
                nb.z.re = nb.tmp;
                nb.iteration++;
            }
            put_pixel(f, nb.x, nb.y, get_color(nb.iteration));
        }
    }
}
#include "fractol.h"

void draw_julia(t_fractol *f)
{
    t_fractale j;

    j.y = -1;
    while (++j.y < HEIGHT)
    {
        j.x = -1;
        while (++j.x < WIDTH)
        {
            j.z.re = f->min_re + j.x * (f->max_re - f->min_re) / WIDTH;
            j.z.im = f->min_im + j.y * (f->max_im - f->min_im) / HEIGHT;
            j.c.re = f->julia_re; // valeurs fixes données par l'utilisateur
            j.c.im = f->julia_im;
            j.iteration = 0;
            while (j.z.re * j.z.re + j.z.im * j.z.im <= 4 && j.iteration < MAX_ITER)
            {
                j.tmp = j.z.re * j.z.re - j.z.im * j.z.im + j.c.re;
                j.z.im = 2 * j.z.re * j.z.im + j.c.im;
                j.z.re = j.tmp;
                j.iteration++;
            }
            put_pixel(f, j.x, j.y, get_color(j.iteration));
        }
    }
}
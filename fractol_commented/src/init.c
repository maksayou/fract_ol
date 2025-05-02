#include "fractol.h"

t_fractol *fractol_init_base(void)
{
    t_fractol *f;

    f = malloc(sizeof(t_fractol));
    if (!f)
        return (NULL);
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
    return (f);
}

void fractol_init_view(t_fractol *f)
{
    f->min_re = -2.0;
    f->max_re = 2.0;
    f->min_im = -2.0;
    f->max_im = 2.0;
}

void fractol_parse_args(t_fractol *f, char **argv)
{
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        f->type = MANDELBROT;
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
    {
        f->type = JULIA;
        if (argv[2] && argv[3])
        {
            f->julia_re = ft_atof(argv[2]);
            f->julia_im = ft_atof(argv[3]);
        }
        else
        {
            f->julia_re = -0.7;
            f->julia_im = 0.27015;
            //printf("argv[1] is %f, and argv[2] is %f\n", f->julia_re, f->julia_im);
        }
    }
    else
    {
        write(1, "Available fractals : mandelbrot | julia [re im]\n", 48);
        free(f);
        exit(1);
    }
}

t_fractol *init_fractol(char **argv)
{
    t_fractol *f;

    f = fractol_init_base();
    if (!f)
        return (NULL);
    fractol_init_view(f);
    fractol_parse_args(f, argv);
    return (f);
}

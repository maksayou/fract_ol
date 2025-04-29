#include "fractol.h"

void start_fractol(char *type)
{
    t_fractol   f;

    f.mlx = mlx_init();
    f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "fract_ol");
    f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
    f.addr = mlx_get_data_addr(f.img, &f.bits_per_pixel, &f.line_length, &f.endian)

    f.min_re = -2.0;
    f.max_re = 2.0;
    f.min_im = -2.0;
    f.max_im = 2.0;
    if (!type || ft_strcmp(type, "mandelbrot") == 0)
        draw_mandelbrot(&f);
    mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
    mlx_loop(f.mlx)
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Usage: ./fractol mandelbrot\n");
        return (1);
    }
    start_fractol(argv[1]);
    return (0);
}
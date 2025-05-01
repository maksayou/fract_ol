/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:26:00 by mayoucha          #+#    #+#             */
/*   Updated: 2025/04/28 20:26:02 by mayoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_program(t_fractol *f)
{
    mlx_destroy_image(f->mlx, f->img);
    mlx_destroy_window(f->mlx, f->win);
    free(f);
    exit(0);
    return (0);
}

void setup_hooks(t_fractol *f)
{
    mlx_hook(f->win, 17, 0, close_program, f);       // Croix de la fenêtre
    mlx_hook(f->win, 2, 1L<<0, handle_key, f);        // Clavier
    mlx_mouse_hook(f->win, handle_mouse, f);          // Souris (molette)
}

int handle_key(int keycode, t_fractol *f)
{
    if (keycode == 65307) // = touche ESC 
        close_program(f);
    return (0);
}

int handle_mouse(int button, int x, int y, t_fractol *f)
{
    double zoom_factor;

    if (button == 4) // Molette haut (Zoom avant)
        zoom_factor = 0.9;
    else if (button == 5) // Molette bas (Zoom arrière)
        zoom_factor = 1.1;
    else
        return (0);
    double mouse_re = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
    double mouse_im = f->min_im + y * (f->max_im - f->min_im) / HEIGHT;
    f->min_re = mouse_re + (f->min_re - mouse_re) * zoom_factor;
    f->max_re = mouse_re + (f->max_re - mouse_re) * zoom_factor;
    f->min_im = mouse_im + (f->min_im - mouse_im) * zoom_factor;
    f->max_im = mouse_im + (f->max_im - mouse_im) * zoom_factor;
    //redraw(f); // définir redraw() pour rafraîchir l'image
    return (0);
}



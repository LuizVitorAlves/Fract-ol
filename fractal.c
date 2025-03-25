/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:46 by lalves-d          #+#    #+#             */
/*   Updated: 2025/03/25 10:43:49 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(t_complex c)
{
    t_complex z;
    double temp;
    int iter;

    z.r = 0;
    z.i = 0;
    iter = 0;
    while (z.r * z.r + z.i * z.i <= 4 && iter < MAX_ITER)
    {
        temp = z.r;
        z.r = z.r * z.r - z.i * z.i + c.r;
        z.i = 2 * temp * z.i + c.i;
        iter++;
    }
    return (iter);
}

int colorize(int iter)
{
    if (iter == MAX_ITER)
        return (0x000000);
    return ((iter * 255 / MAX_ITER) << 16);
}

void draw_mandelbrot(t_fractol *fractol)
{
    int x;
    int y;
    t_complex c;
    int iter;
    int color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c.r = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            c.i = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            iter = mandelbrot(c);
            color = colorize(iter);
            mlx_pixel_put(fractol->mlx, fractol->win, x, y, color); // Desenha o pixel
            x++;
        }
        y++;
    }
}

int julia(t_complex z, t_complex c)
{
    double temp;
    int iter = 0;

    while (z.r * z.r + z.i * z.i <= 4 && iter < MAX_ITER)
    {
        temp = z.r;
        z.r = z.r * z.r - z.i * z.i + c.r;
        z.i = 2 * temp * z.i + c.i;
        iter++;
    }
    return iter;
}

void draw_julia(t_fractol *fractol)
{
    int x;
    int y;
    t_complex z;
    int iter;
    int color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            z.r = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            z.i = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            iter = julia(z, fractol->c);
            color = colorize(iter);
            mlx_pixel_put(fractol->mlx, fractol->win, x, y, color); // Desenhando o pixel
            x++;
        }
        y++;
    }
}

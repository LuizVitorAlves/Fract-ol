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
    int r, g, b;
    double t = (double)iter / MAX_ITER;
    
    r = (int)(sin(0.08 * iter + t) * 100 + 128);
    g = (int)(sin(0.16 * iter + 2 + t) * 100 + 128);
    b = (int)(sin(0.24 * iter + 4 + t) * 100 + 128);
    
    return (r << 16 | g << 8 | b);
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
            c.r = fractol->min_x + (x / (double)WIDTH) * (fractol->max_x - fractol->min_x);
            c.i = fractol->max_y - (y / (double)HEIGHT) * (fractol->max_y - fractol->min_y);
            iter = mandelbrot(c);
            color = colorize(iter);
            mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
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
            z.r = fractol->min_x + (x / (double)WIDTH) * (fractol->max_x - fractol->min_x);
            z.i = fractol->max_y - (y / (double)HEIGHT) * (fractol->max_y - fractol->min_y);
            iter = julia(z, fractol->c);
            color = colorize(iter);
            mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
            x++;
        }
        y++;
    }
}
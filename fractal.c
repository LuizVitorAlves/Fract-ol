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

int	mandelbrot(t_complex c)
{
	t_complex	z;
	double		temp;
	int			iter;

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

static void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbrot(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.r = fractol->min_x + (x / (double)WIDTH)
				* (fractol->max_x - fractol->min_x);
			c.i = fractol->max_y - (y / (double)HEIGHT)
				* (fractol->max_y - fractol->min_y);
			iter = mandelbrot(c);
			put_pixel_to_image(fractol->draw, x, y, colorize(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->draw->img, 0, 0);
}

int	julia(t_complex z, t_complex c)
{
	double	temp;
	int		iter;

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

void	draw_julia(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	z;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.r = fractol->min_x + (x / (double)WIDTH)
				* (fractol->max_x - fractol->min_x);
			z.i = fractol->max_y - (y / (double)HEIGHT)
				* (fractol->max_y - fractol->min_y);
			iter = julia(z, fractol->c);
			put_pixel_to_image(fractol->draw, x, y, colorize(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->draw->img, 0, 0);
}

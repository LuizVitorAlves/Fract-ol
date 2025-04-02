/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:57 by lalves-d          #+#    #+#             */
/*   Updated: 2025/03/25 10:44:01 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	close_esc(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

void	apply_zoom(t_fractol *fractol, double mouse_re,
					double mouse_im, int button)
{
	double	zoom;

	if (button == ZOOM_IN)
		zoom = 1 / ZOOM_FACTOR;
	else
		zoom = ZOOM_FACTOR;
	fractol->min_x = mouse_re + (fractol->min_x - mouse_re) * zoom;
	fractol->max_x = mouse_re + (fractol->max_x - mouse_re) * zoom;
	fractol->min_y = mouse_im + (fractol->min_y - mouse_im) * zoom;
	fractol->max_y = mouse_im + (fractol->max_y - mouse_im) * zoom;
}

int	mouse_zoom(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_re;
	double	mouse_im;

	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		mouse_re = fractol->min_x + (x / (double)WIDTH)
			* (fractol->max_x - fractol->min_x);
		mouse_im = fractol->max_y - (y / (double)HEIGHT)
			* (fractol->max_y - fractol->min_y);
		apply_zoom(fractol, mouse_re, mouse_im, button);
		if (ft_strcmp(fractol->type, "mandelbrot") == 0)
			draw_mandelbrot(fractol);
		else if (ft_strcmp(fractol->type, "julia") == 0)
			draw_julia(fractol);
	}
	return (0);
}

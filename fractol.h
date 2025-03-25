/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:44:33 by lalves-d          #+#    #+#             */
/*   Updated: 2025/03/25 10:44:35 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 1000

typedef struct s_complex {
    double r;
    double i;
} t_complex;

typedef struct s_fractol {
    void    *mlx;
    void    *win;
} t_fractol;

//events
int close_esc(int keycode, void *param);
int close_window(void *param);

//fractal
int mandelbrot(t_complex c);
void draw_mandelbrot(t_fractol *fractol);
int colorize(int iter);

#endif
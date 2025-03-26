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
#include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 1000
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ZOOM_FACTOR 1.2

typedef struct s_complex {
    double r;
    double i;
} t_complex;

typedef struct s_fractol {
    void    *mlx;
    void    *win;
    double  min_x;
    double  max_x;
    double  min_y;
    double  max_y;
    t_complex    c;
    char *type;
} t_fractol;

//events
int close_esc(int keycode, void *param);
int close_window(void *param);
int mouse_zoom(int button, int x, int y, t_fractol *fractol);

//fractal
int mandelbrot(t_complex c);
void draw_mandelbrot(t_fractol *fractol);
int colorize(int iter);
int julia(t_complex z, t_complex c);
void draw_julia(t_fractol *fractol);

//utils
void	ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);

#endif
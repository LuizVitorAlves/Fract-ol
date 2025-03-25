/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:27 by lalves-d          #+#    #+#             */
/*   Updated: 2025/03/25 10:50:56 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fractol.h"

int	main()
{
	void	*mlx;
	void	*win;
    t_fractol   fractol;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Fract-ol");
    draw_mandelbrot(&fractol);
	mlx_key_hook(win, close_esc, NULL);
    mlx_hook(win, 17, 0, close_window, NULL);
	mlx_loop(mlx);
	return (0);
}

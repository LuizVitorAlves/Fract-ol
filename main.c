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

static int	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (0);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol->win)
		return (0);
	return (1);
}

static int	check_fractal_type(int argc, char **argv, t_fractol *fractol)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
	{
		draw_mandelbrot(fractol);
		return (1);
	}
	if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		fractol->c.r = atof(argv[2]);
		fractol->c.i = atof(argv[3]);
		draw_julia(fractol);
		return (1);
	}
	return (0);
}

static void	print_usage(void)
{
	ft_putstr("Usage:\n");
	ft_putstr("  ./fractol mandelbrot\n");
	ft_putstr("  ./fractol julia <c_r> <c_i>\n");
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 2 && argc != 4)
	{
		print_usage();
		return (1);
	}
	if (!init_fractol(&fractol))
		return (1);
	if (!check_fractal_type(argc, argv, &fractol))
	{
		ft_putstr("Invalid fractal type. Use mandelbrot or julia.\n");
		return (1);
	}
	mlx_key_hook(fractol.win, close_esc, NULL);
	mlx_hook(fractol.win, 17, 0, close_window, NULL);
	mlx_loop(fractol.mlx);
	return (0);
}

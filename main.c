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

/*int	main(void)
{
	t_fractol	fractol;

	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		return (1);
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol.win)
		return (1);
    fractol.c.r = -0.7;
    fractol.c.i = 0.27015;    
	draw_julia(&fractol);
	mlx_key_hook(fractol.win, close_esc, NULL);
	mlx_hook(fractol.win, 17, 0, close_window, NULL);
	mlx_loop(fractol.mlx);
	return (0);
}
*/

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

static int	check_fractal_type(char *type, t_fractol *fractol, char **argv)
{
	if (ft_strcmp(type, "mandelbrot") == 0)
	{
		draw_mandelbrot(fractol);
		return (1);
	}
	else if (ft_strcmp(type, "julia") == 0)
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
	ft_putstr("Usage: ./fractol mandelbrot/julia c_r c_i\n");
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 4)
	{
		print_usage();
		return (1);
	}
	if (!init_fractol(&fractol))
		return (1);
	if (!check_fractal_type(argv[1], &fractol, argv))
	{
		ft_putstr("Invalid fractal type. Use mandelbrot or julia.\n");
		return (1);
	}
	mlx_key_hook(fractol.win, close_esc, NULL);
	mlx_hook(fractol.win, 17, 0, close_window, NULL);
	mlx_loop(fractol.mlx);
	return (0);
}

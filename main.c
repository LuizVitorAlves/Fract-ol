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

#include "mlx.h"
#include <stdlib.h>

int key_hook(int keycode, void *param) 
{
    (void)param;
    if (keycode == 65307)
        exit(0);
    return (0);
}

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int	main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Fract-ol");
	mlx_key_hook(win, key_hook, NULL);
    mlx_hook(win, 17, 0, close_window, NULL);
	mlx_loop(mlx);
	return (0);
}

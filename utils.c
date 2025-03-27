/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:05:09 by lalves-d          #+#    #+#             */
/*   Updated: 2025/03/25 16:05:11 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
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

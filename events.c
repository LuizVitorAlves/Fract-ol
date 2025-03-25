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

int close_esc(int keycode, void *param) 
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

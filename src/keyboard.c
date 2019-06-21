/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:14:27 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 18:11:32 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_max(t_fract *data, int key)
{
	if (key == 126)
		data->imax += 10;
	if (key == 125)
		data->imax -= 10;
	if (key == 17 && data->fract == 2)
	{
		data->c_r = -0.772691322542185;
		data->c_i = 0.124281466072787;
	}
	if (key == 15 && data->fract == 2)
	{
		data->c_r = 0.285;
		data->c_i = 0.01;
	}
}

int		deal_key(int key, void *data)
{
	if (key == 126 || key == 125 || key == 15 || key == 17)
	{
		change_max(((t_fract *)data), key);
		mlx_clear_window(((t_fract *)data)->mlx, ((t_fract *)data)->win);
		if (((t_fract *)data)->fract == 1)
			draw_mandelbrot(data);
		else if (((t_fract *)data)->fract == 2)
			draw_julia(data);
		else if (((t_fract *)data)->fract == 3)
			draw_burning(data);
	}
	if (key == 256)
	{
		if (((t_fract *)data)->ctrl)
			((t_fract *)data)->ctrl *= -1;
	}
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

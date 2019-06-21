/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:56:23 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 17:56:38 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_pxl_to_img(t_fract *data, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_adr + 4 * WIDTH * y + x * 4, &color, sizeof(int));
	}
}

int			expose_hook(t_fract *data)
{
	mlx_clear_window(((t_fract *)data)->mlx, ((t_fract *)data)->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int			check_color(char *str)
{
	int		i;

	i = 2;
	if (ft_strlen(str) != 8)
		return (0);
	if (str[0] != '0' && str[1] != 'x')
		return (0);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] <= 'F'))
			i++;
		else
			return (0);
	}
	return (1);
}

int			get_color(char *str)
{
	int		color;
	int		i;

	i = 2;
	color = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			color += ft_power(16, 7 - i) * (str[i] - '0');
		if (str[i] >= 'A' && str[i] <= 'F')
			color += ft_power(16, 7 - i) * (str[i] - 'A' + 10);
		i++;
	}
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:04:08 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 20:14:48 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing_line(t_data *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	x;
	float	y;

	x = (float)data->x;
	y = (float)data->y;
	x_step = (int)data->x1 - x;
	y_step = (int)data->y1 - y;
	max = max_nmb(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data->x1 - x) || (int)(data->y1 - y))
	{	
		my_mlx_pixel_put(data, data->begin_point_x + x,
			data->begin_point_y + y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	drawing_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				iso_x(x, y, data);
			if (y < data->height - 1)
				iso_y(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

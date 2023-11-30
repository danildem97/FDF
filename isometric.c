/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:19:09 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 20:14:26 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(int *x, int *y, int z, t_data *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	iso_x(int x, int y, t_data *data)
{
	fill_x_y(x, y, data);
	data->x1 = x + 1;
	data->y1 = y;
	fill_z(data);
	check_color(data);
	zoom_add(data);
	isometric(&data->x, &data->y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	drawing_line(data);
}

void	iso_y(int x, int y, t_data *data)
{
	fill_x_y(x, y, data);
	data->x1 = x;
	data->y1 = y + 1;
	fill_z(data);
	check_color(data);
	zoom_add(data);
	isometric(&data->x, &data->y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	drawing_line(data);
}

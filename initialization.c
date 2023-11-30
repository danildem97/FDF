/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:55:50 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 20:22:15 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_data *data)
{
	data->color = 0;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->constant = 1;
	data->endian = 0;
	data->zoom_height = 1;
	data->win_width = 2000;
	data->win_height = 1000;
	data->angle = 0.9;
	if (data->win_width >= data->win_height)
		data->constant = data->win_width / data->win_height;
	data->zoom = data->win_width / data->width / 1.5 / data->constant;
	data->begin_point_x = data->win_width / 2 - data->width / 3;
	data->begin_point_y = data->win_height / 2 - data->height / 3 * data->zoom;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:21:28 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 19:04:52 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_nmb(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	mod(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	zoom_add(t_data *data)
{
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->z *= data->zoom_height;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->z1 *= data->zoom_height;
}

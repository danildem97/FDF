/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:52:33 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 18:05:09 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_z(t_data *data)
{
	data->z = data->matrix[data->y][data->x];
	data->z1 = data->matrix[data->y1][data->x1];
}

void	fill_x_y(int x, int y, t_data *data)
{
	data->x = x;
	data->y = y;
}

int	**malloc_matrix(int height, int width)
{
	int	i;
	int	**answer;

	i = 0;
	answer = (int **)malloc(sizeof(int *) * (height + 1));
	while (i < height)
	{
		answer[i] = (int *)malloc(sizeof(int) * (width + 1));
		i++;
	}
	return (answer);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_width && y < data->win_height
		&& x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
	return (1);
}

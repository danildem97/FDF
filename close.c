/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:48:50 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 18:08:33 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_2d_matrix(int **matrix, t_data *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	escape(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->matrix)
		free_2d_matrix(data->matrix, data);
	if (data)
		free(data);
	exit(1);
}

int	keyboard(int button, t_data *data)
{
	if (button == 53)
		escape(data);
	return (0);
}

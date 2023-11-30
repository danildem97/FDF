/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:32:59 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 20:33:20 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error("!!Invalid number of arguments!!\n");
	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (0);
	read_file(argv[1], data);
	init_vars(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	drawing_map(data);
	mlx_hook(data->win_ptr, 2, 0, keyboard, data);
	mlx_hook(data->win_ptr, 17, 0, escape, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

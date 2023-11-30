/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:41:08 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 20:22:35 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_color(t_data *data)
{
	if (data->z >= 2 || data->z1 >= 2)
		data->color = 0x0000FF;
	else if (data->z >= 1 || data->z1 >= 1)
		data->color = 0xFF9900;
	else if (data->z >= 3 || data->z1 >= 3)
		data->color = 0xA64D79;
	else if (data->z >= 5 || data->z1 >= 5)
		data->color = 0xFFFF00;
	else if (data->z >= 10 || data->z1 >= 10)
		data->color = 0xFF9900;
	else if (data->z <= 0 || data->z1 <= 0)
		data->color = 0x674EA7;
	else
		data->color = 0x00FFFF;
}

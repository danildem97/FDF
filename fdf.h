/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:33:41 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 20:24:36 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>

typedef struct s_data
{
	int		width;
	int		height;
	int		**matrix;
	int		color;
	int		zoom;
	double	zoom_height;
	int		win_width;
	int		win_height;
	int		begin_point_x;
	int		begin_point_y;
	float	angle;
	int		x;
	int		y;
	int		z;
	int		x1;
	int		y1;
	int		z1;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		constant;
}				t_data;

int		count_symbols(char *line, char delim);
int		**malloc_matrix(int height, int width);
void	read_file(char *file, t_data *data);
void	init_vars(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fill_x_y(int x, int y, t_data *data);
void	fill_z(t_data *data);
int		max_nmb(int a, int b);
int		mod(int a);
void	iso_x(int x, int y, t_data *data);
void	iso_y(int x, int y, t_data *data);
void	drawing_line(t_data *data);
void	drawing_map(t_data *data);
void	check_color(t_data *data);
int		keyboard(int button, t_data *data);
int		escape(t_data *data);
int		error(char *msg);
void	zoom_add(t_data *data);
void	check_color(t_data *data);
#endif
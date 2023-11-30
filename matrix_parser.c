/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:18:14 by ddemydov          #+#    #+#             */
/*   Updated: 2023/07/25 20:37:24 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_symbols(char *line, char delim)
{
	int		answer;
	int		i;
	char	**str;

	answer = 0;
	i = 0;
	str = ft_split(line, ' ');
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (i);
}

int	get_width(char *file)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		error("Error while trying to read file.\n");
	width = 0;
	line = get_next_line(fd);
	width = count_symbols(line, ' ');
	free(line);
	close (fd);
	return (width);
}

int	get_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		error("Error while trying to read file.\n");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	parse_matrix(int *matrix, char *line)
{
	char	**str;
	int		index;

	index = 0;
	str = ft_split(line, ' ');
	while (str[index])
	{
		matrix[index] = ft_atoi(str[index]);
		free(str[index]);
		index++;
	}
	free(str);
}

void	read_file(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		index;

	index = 0;
	data->height = get_height(file);
	data->width = get_width(file);
	data->matrix = malloc_matrix(data->height, data->width);
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		error("Error while trying to read file.\n");
	while (index < data->height)
	{
		line = get_next_line(fd);
		parse_matrix(data->matrix[index], line);
		index++;
		free(line);
	}
	close(fd);
	data->matrix[index] = 0;
}

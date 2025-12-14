/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:38:28 by iogul             #+#    #+#             */
/*   Updated: 2025/12/14 14:38:46 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

int	get_height(char *file_path)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		write_error();
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	*get_width(char *file_path, int height)
{
	int		fd;
	char	*line;
	int		*w_arr;
	int		i;

	i = 0;
	w_arr = (int *)malloc(sizeof(int) * height);
	if (!w_arr)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		write_error();
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean_newline(line);
		w_arr[i++] = split_count(line, ' ');
		free(line);
	}
	close(fd);
	return (w_arr);
}

void	fill_matrix(int *z_line, int *color_line, char *line)
{
	char	**values;
	char	*comma;
	int		i;

	i = 0;
	clean_newline(line);
	values = ft_split(line, ' ');
	if (!values)
		write_error();
	while (values[i])
	{
		z_line[i] = ft_atoi(values[i]);
		comma = ft_strchr(values[i], ',');
		if (comma)
			color_line[i] = ft_atoi_hex(comma + 1);
		else
			color_line[i] = 0xFFFFFF;
		i++;
	}
	split_free(values);
}

static void	alloc_map_arrays(t_fdf *data)
{
	data->map.matrix = (int **)malloc(sizeof(int *) * (data->map.height + 1));
	data->map.matrix_color = (int **)malloc(sizeof(int *)
			* (data->map.height + 1));
	if (!data->map.matrix || !data->map.matrix_color)
		write_error();
}

void	read_map(char *file_path, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->map.height = get_height(file_path);
	data->map.width = get_width(file_path, data->map.height);
	alloc_map_arrays(data);
	fd = open(file_path, O_RDONLY);
	i = 0;
	while (i < data->map.height)
	{
		line = get_next_line(fd);
		data->map.matrix[i] = malloc(sizeof(int) * data->map.width[i]);
		data->map.matrix_color[i] = malloc(sizeof(int) * data->map.width[i]);
		if (!data->map.matrix[i] || !data->map.matrix_color[i])
			write_error();
		fill_matrix(data->map.matrix[i], data->map.matrix_color[i], line);
		free(line);
		i++;
	}
	close(fd);
}

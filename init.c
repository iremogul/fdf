/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:46:33 by iogul             #+#    #+#             */
/*   Updated: 2025/12/14 14:46:51 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	open_window(t_fdf *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr == NULL)
	{
		free_map(data);
		get_next_line(-1);
		write(2, "Error: MLX Init Failed\n", 23);
		exit(1);
	}
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "FDF");
	if (data->mlx.win_ptr == NULL)
	{
		free_map(data);
		get_next_line(-1);
		mlx_destroy_display(data->mlx.mlx_ptr);
		free(data->mlx.mlx_ptr);
		write(2, "Error: Window Creation Failed\n", 30);
		exit(1);
	}
}

void	init_image(t_fdf *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	if (!data->img.img_ptr || !data->img.addr)
		write_error();
}

static void	get_map_limits(t_fdf *data, int *min_z, int *max_z, int *max_w)
{
	int	x;
	int	y;

	*min_z = data->map.matrix[0][0];
	*max_z = data->map.matrix[0][0];
	*max_w = 0;
	y = 0;
	while (y < data->map.height)
	{
		if (data->map.width[y] > *max_w)
			*max_w = data->map.width[y];
		x = 0;
		while (x < data->map.width[y])
		{
			if (data->map.matrix[y][x] < *min_z)
				*min_z = data->map.matrix[y][x];
			if (data->map.matrix[y][x] > *max_z)
				*max_z = data->map.matrix[y][x];
			x++;
		}
		y++;
	}
}

void	init_camera(t_fdf *data)
{
	int		min_z;
	int		max_z;
	int		max_w;
	float	span[2];

	get_map_limits(data, &min_z, &max_z, &max_w);
	span[0] = (max_w + data->map.height) * cos(0.523599);
	span[1] = (max_w + data->map.height) * sin(0.523599) + (max_z - min_z);
	if (span[0] < 1)
		span[0] = 1;
	if (span[1] < 1)
		span[1] = 1;
	data->cam.zoom = (WIN_WIDTH * 0.8) / span[0];
	if ((WIN_HEIGHT * 0.8) / span[1] < data->cam.zoom)
		data->cam.zoom = (WIN_HEIGHT * 0.8) / span[1];
	if (data->cam.zoom < 0.1)
		data->cam.zoom = 0.1;
	data->cam.angle = 0.523599;
	data->cam.offset_x = WIN_WIDTH / 2;
	data->cam.offset_y = WIN_HEIGHT / 2;
}

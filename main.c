/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:48:34 by iogul             #+#    #+#             */
/*   Updated: 2025/12/14 14:48:37 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include "get_next_line.h"

void	check_file_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".fdf", 4) != 0)
		write_error();
}

int	close_window(t_fdf *data)
{
	free_map(data);
	if (data->img.img_ptr != NULL)
		mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	if (data->mlx.win_ptr != NULL)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx.mlx_ptr);
		free(data->mlx.mlx_ptr);
	}
	get_next_line(-1);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_fdf *data)
{
	if (keycode == 65307)
		close_window(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	data.map.matrix = NULL;
	data.mlx.mlx_ptr = NULL;
	data.mlx.win_ptr = NULL;
	if (argc != 2)
		write_error();
	check_file_name(argv[1]);
	read_map(argv[1], &data);
	init_camera(&data);
	open_window(&data);
	init_image(&data);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.win_ptr,
		data.img.img_ptr, 0, 0);
	mlx_key_hook(data.mlx.win_ptr, key_handler, &data);
	mlx_hook(data.mlx.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}

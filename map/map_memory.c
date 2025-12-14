/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:37:21 by iogul             #+#    #+#             */
/*   Updated: 2025/12/14 14:37:36 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	free_utils(t_fdf *data)
{
	int	i;

	i = 0;
	if (data->map.matrix)
	{
		while (i < data->map.height)
		{
			if (data->map.matrix[i])
				free(data->map.matrix[i]);
			if (data->map.matrix_color && data->map.matrix_color[i])
				free(data->map.matrix_color[i]);
			i++;
		}
		free(data->map.matrix);
		data->map.matrix = NULL;
	}
}

void	free_map(t_fdf *data)
{
	free_utils(data);
	if (data->map.matrix_color)
	{
		free(data->map.matrix_color);
		data->map.matrix_color = NULL;
	}
	if (data->map.width)
	{
		free(data->map.width);
		data->map.width = NULL;
	}
}

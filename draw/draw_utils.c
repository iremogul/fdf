/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:43:15 by iogul             #+#    #+#             */
/*   Updated: 2025/12/14 14:47:46 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	my_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = data->img.addr + (y * data->img.line_length
				+ x * (data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	project(t_point *p, t_fdf *data)
{
	int	original_x;
	int	original_y;

	p->x *= data->cam.zoom;
	p->y *= data->cam.zoom;
	p->z *= data->cam.zoom;
	original_x = p->x;
	original_y = p->y;
	p->x = (original_x - original_y) * cos(data->cam.angle);
	p->y = (original_x + original_y) * sin(data->cam.angle) - p->z;
	p->x += data->cam.offset_x;
	p->y += data->cam.offset_y;
}

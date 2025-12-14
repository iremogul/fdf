/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:44:13 by iogul             #+#    #+#             */
/*   Updated: 2025/12/14 14:44:30 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_steps(t_point start, t_point end, float *step, int *max)
{
	float	dx;
	float	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	if (my_abs((int)dx) > my_abs((int)dy))
		*max = my_abs((int)dx);
	else
		*max = my_abs((int)dy);
	*step = dx / *max;
	*(step + 1) = dy / *max;
}

void	draw_line(t_point start, t_point end, t_fdf *data)
{
	float	c_xy[2];
	float	step[2];
	int		max;
	int		i;

	project(&start, data);
	project(&end, data);
	c_xy[0] = start.x;
	c_xy[1] = start.y;
	calc_steps(start, end, step, &max);
	i = 0;
	while (i <= max)
	{
		my_pixel_put(data, (int)c_xy[0], (int)c_xy[1], start.color);
		c_xy[0] += step[0];
		c_xy[1] += step[1];
		i++;
	}
}

static void	setup_point(t_point *p, int x, int y, t_fdf *data)
{
	p->x = x;
	p->y = y;
	p->z = data->map.matrix[y][x];
	p->color = data->map.matrix_color[y][x];
}

static void	draw_grid_point(t_fdf *data, int x, int y)
{
	t_point	p1;
	t_point	p2;

	setup_point(&p1, x, y, data);
	if (x < data->map.width[y] - 1)
	{
		setup_point(&p2, x + 1, y, data);
		draw_line(p1, p2, data);
	}
	if (y < data->map.height - 1)
	{
		if (x < data->map.width[y + 1])
		{
			setup_point(&p2, x, y + 1, data);
			draw_line(p1, p2, data);
		}
	}
}

void	draw_map(t_fdf *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width[y])
		{
			draw_grid_point(data, x, y);
			x++;
		}
		y++;
	}
}

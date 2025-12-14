#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define COLOR_DEFAULT 0xFFFFFF
# define WIN_WIDTH 1500
# define WIN_HEIGHT 1500

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		**matrix;
	int		**matrix_color;
	int		*width;
	int		height;
}	t_map;

typedef struct s_camera
{
	float	zoom;
	float	angle;
	int		offset_x;
	int		offset_y;
}	t_camera;

typedef struct s_fdf
{
	t_mlx		mlx;
	t_img		img;
	t_map		map;
	t_camera	cam;
}	t_fdf;

void	open_window(t_fdf *data);
void	init_image(t_fdf *data);
void	init_camera(t_fdf *data);
void	read_map(char *file_path, t_fdf *data);
void	write_error(void);
void	free_map(t_fdf *data);
void	clean_newline(char *line);
void	split_free(char **str);
int		split_count(char *str, char c);
int		ft_atoi_hex(char *hex);
void	draw_map(t_fdf *data);
void	draw_line(t_point start, t_point end, t_fdf *data);
void	my_pixel_put(t_fdf *data, int x, int y, int color);
void	project(t_point *p, t_fdf *data);
int		my_abs(int n);
int		close_window(t_fdf *data);
int		key_handler(int keycode, t_fdf *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:59:46 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/13 20:43:05 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	use_pixel(t_map *game, int y, int x)
{
	draw_circle(game, x, y);
	draw_ray(game, x, y, game->player_direction);
}

void	draw_circle(t_map *game, int x, int y)
{
	int	color;
	int	i;
	int	j;

	color = 0x00FF00;
	i = x - 4;
	while (i <= x + 4)
	{
		j = y - 4;
		while (j <= y + 4)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, i, j, color);
			++j;
		}
		++i;
	}
}

void	draw_ray(t_map *game, int x, int y, double angle)
{
	int		raycolor;
	int		k;
	double	dir_x;
	double	dir_y;

	raycolor = 0xFF0000;
	angle = fmod(angle, 2 * PI);
	dir_x = cos(angle);
	dir_y = sin(angle);
	k = 0;
	while (k < 20)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, (int)round(x + k * dir_x),
			(int)round(y + k * dir_y), raycolor);
		k++;
	}
}

void	draw_horizontal_grid(t_map *game)
{
	int	size;
	int	color;
	int	i;
	int	x;
	int	y;

	size = 64;
	color = 0x0000FF;
	i = 0;
	while (i < game->height)
	{
		++i;
		y = i * size;
		x = 0;
		while (x < game->width * size)
		{
			++x;
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, color);
		}
	}
}

void	draw_vertical_grid(t_map *game)
{
	int	size;
	int	color;
	int	j;
	int	x;
	int	y;

	size = 64;
	color = 0x0000FF;
	j = 0;
	while (j < game->width)
	{
		++j;
		x = j * size;
		y = 0;
		while (y < game->height * size)
		{
			++y;
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, color);
		}
	}
}

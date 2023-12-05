/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:59:46 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/05 20:50:29 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	use_pixel(t_game *game, int y, int x)
{
	int	size;

	size = 64;
	draw_circle(game, x, y, size);
	draw_ray(game, x, y, size);
}

void	draw_circle(t_game *game, int x, int y, int size)
{
	int	color;
	int	center[2];
	int	i[2];
	int	dx;
	int	dy;

	color = 0x00FF00;
	center[0] = x + size / 2;
	center[1] = y + size / 2;
	i[0] = 0;
	while (i[0] < size)
	{
		i[1] = 0;
		while (i[1] < size)
		{
			dx = center[0] - (x + i[0]);
			dy = center[1] - (y + i[1]);
			if (dx * dx + dy * dy <= (size / 4) * (size / 4))
				mlx_pixel_put(game->mlx, game->mlx_win, x + i[0], y + i[1],
					color);
			++i[1];
		}
		++i[0];
	}
}

void	draw_ray(t_game *game, int x, int y, int size)
{
	int	centerx;
	int	centery;
	int	raycolor;
	int	k;

	centerx = x + size / 2;
	centery = y + size / 2;
	raycolor = 0xFF0000;
	k = 0;
	while (k < centery)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, centerx, centery - k, raycolor);
		++k;
	}
}

void	draw_horizontal_grid(t_game *game)
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

void	draw_vertical_grid(t_game *game)
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

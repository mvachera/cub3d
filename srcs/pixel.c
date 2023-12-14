/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:59:46 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/14 17:19:17 by mvachera         ###   ########.fr       */
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
	int raycolor;
    double dir_x;
    double dir_y;

    raycolor = 0xFF0000;
    angle = fmod(angle, 2 * PI);
    dir_x = cos(angle - PI / 2);
    dir_y = sin(angle - PI / 2);

    int k = 0;
    while ((int)round(y + k * dir_y) >= 0 && (int)round(x + k * dir_x) >= 0
        && game->map_expand[(int)round(y + k * dir_y)] != NULL
		&& game->map_expand[(int)round(y + k * dir_y)][(int)round(x + k * dir_x)])
    {
        // Calcul des coordonnées du pixel suivant le rayon
        int next_x = (int)round(x + k * dir_x);
        int next_y = (int)round(y + k * dir_y);

        // Affichage du pixel
        mlx_pixel_put(game->mlx, game->mlx_win, next_x, next_y, raycolor);

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:48:58 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/12 20:20:09 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d"

double degrees_to_radians(double degrees)
{
    return degrees * (PI / 180.0);
}

double radians_to_degrees(double radians)
{
    return radians * (180.0 / PI);
}

void rotate_left(t_game *game)
{
    game->player_direction -= ROTATION_SPEED;
    if (game->player_direction < 0)
        game->player_direction += 2 * PI;
    // Appelez la fonction de redessin ici
}

void rotate_right(t_game *game)
{
    game->player_direction += ROTATION_SPEED;
    if (game->player_direction >= 2 * PI)
        game->player_direction -= 2 * PI;
    // Appelez la fonction de redessin ici
}

void	draw_ray2(t_map *game, int x, int y, double angle)
{
	int		raycolor;
	int		k;
	double	dir_x;
	double	dir_y;

	raycolor = 0xFF0000;
	angle = fmod(angle, 2 * M_PI);
	dir_x = cos(angle);
	dir_y = sin(angle);
	k = 0;
	while (k < 20)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x + (int)(k * dir_x), y
				+ (int)(k * dir_y), raycolor);
		k++;
	}
}

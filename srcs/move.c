/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:57:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/13 20:33:33 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_pos(t_map *game, int new_y, int new_x)
{
	game->player_y = new_y;
	game->player_x = new_x;
}

int	move_up(t_map *game)
{
	double	new_y;
	double	new_x;

	new_y = game->player_y - 2 * cos(game->player_direction);
	new_x = game->player_x + 2 * sin(game->player_direction);
	if (game->map_expand[(int)round(new_y)][(int)round(new_x)] == '1')
		return (0);
	// else if (game->map_expand[(int)new_y][(int)new_x] == '1')
		// small_new_pos(game, new_y, new_x);
	else
		new_pos(game, (int)round(new_y), (int)round(new_x));
	print_map(game);
	return (0);
}

int	move_left(t_map *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x - 2 * cos(game->player_direction);
	new_y = game->player_y - 2 * sin(game->player_direction);
	if (game->map_expand[(int)round(new_y)][(int)round(new_x)] == '1')
		return (0);
	// else if (game->map_expand[(int)new_y][(int)new_x] == '1')
		// small_new_pos(game, new_y, new_x);
	else
		new_pos(game, (int)round(new_y), (int)round(new_x));
	print_map(game);
	return (0);
}

int	move_right(t_map *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + 2 * cos(game->player_direction);
	new_y = game->player_y + 2 * sin(game->player_direction);
	if (game->map_expand[(int)round(new_y)][(int)round(new_x)] == '1')
		return (0);
	// else if (game->map_expand[(int)new_y][(int)new_x] == '1')
		// small_new_pos(game, new_y, new_x);
	else
		new_pos(game, (int)round(new_y), (int)round(new_x));
	print_map(game);
	return (0);
}

int	move_down(t_map *game)
{
	double	new_y;
	double	new_x;

	new_y = game->player_y + 2 * cos(game->player_direction);
	new_x = game->player_x - 2 * sin(game->player_direction);
	if (game->map_expand[(int)round(new_y)][(int)round(new_x)] == '1')
		return (0);
	// else if (game->map_expand[(int)new_y][(int)new_x] == '1')
		// small_new_pos(game, new_y, new_x);
	else
		new_pos(game, (int)round(new_y), (int)round(new_x));
	print_map(game);
	return (0);
}

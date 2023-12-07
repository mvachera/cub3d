/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:57:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/06 19:46:23 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_pos(t_map *game, int new_y, int new_x)
{
	game->map_expand[game->player_y][game->player_x] = '0';
	game->player_y = new_y;
	game->player_x = new_x;
	game->map_expand[game->player_y][game->player_x] = game->start_direction;
}

int	move_up(t_map *game)
{
	int	new_y;

	new_y = game->player_y - 3;
	if (game->map_expand[new_y][game->player_x] == '1')
		return (0);
	else
		new_pos(game, new_y, game->player_x);
	print_map(game);
	return (0);
}

int	move_left(t_map *game)
{
	int	new_x;

	new_x = game->player_x - 3;
	if (game->map_expand[game->player_y][new_x] == '1')
		return (0);
	else
		new_pos(game, game->player_y, new_x);
	print_map(game);
	return (0);
}

int	move_right(t_map *game)
{
	int	new_x;

	new_x = game->player_x + 3;
	if (game->map_expand[game->player_y][new_x] == '1')
		return (0);
	else
		new_pos(game, game->player_y, new_x);
	print_map(game);
	return (0);
}

int	move_down(t_map *game)
{
	int	new_y;

	new_y = game->player_y + 3;
	if (game->map_expand[new_y][game->player_x] == '1')
		return (0);
	else
		new_pos(game, new_y, game->player_x);
	print_map(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:57:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/08 21:04:12 by mvachera         ###   ########.fr       */
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
	int	new_y;

	new_y = game->player_y - 1;
	if (game->map_expand[game->player_y - 1][game->player_x] == '1')
		return (0);
	else if (game->map_expand[new_y][game->player_x] == '1')
		small_new_pos(game, new_y, game->player_x);
	else
		new_pos(game, new_y, game->player_x);
	print_map(game);
	return (0);
}

int	move_left(t_map *game)
{
	int	new_x;

	new_x = game->player_x - 1;
	if (game->map_expand[game->player_y][game->player_x - 1] == '1')
		return (0);
	else if (game->map_expand[game->player_y][new_x] == '1')
		small_new_pos(game, game->player_y, new_x);
	else
		new_pos(game, game->player_y, new_x);
	print_map(game);
	return (0);
}

int	move_right(t_map *game)
{
	int	new_x;

	new_x = game->player_x + 1;
	if (game->map_expand[game->player_y][game->player_x + 1] == '1')
		return (0);
	else if (game->map_expand[game->player_y][new_x] == '1')
		small_new_pos(game, game->player_y, new_x);
	else
		new_pos(game, game->player_y, new_x);
	print_map(game);
	return (0);
}

int	move_down(t_map *game)
{
	int	new_y;

	new_y = game->player_y + 1;
	if (game->map_expand[game->player_y + 1][game->player_x] == '1')
		return (0);
	else if (game->map_expand[new_y][game->player_x] == '1')
		small_new_pos(game, new_y, game->player_x);
	else
		new_pos(game, new_y, game->player_x);
	print_map(game);
	return (0);
}

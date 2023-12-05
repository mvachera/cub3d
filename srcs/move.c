/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:57:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/05 19:32:22 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_pos(t_game *game, int new_y, int new_x)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_y = new_y;
	game->player_x = new_x;
	game->map[game->player_y][game->player_x] = game->start_direction;
}

void	move_up(t_game *game)
{
	int	new_y;

	new_y = game->player_y - 1;
	if (game->map[new_y][game->player_x] == '1')
		return ;
	else
		new_pos(game, new_y, game->player_x);
	print_map(game);
	draw_horizontal_grid(game);
	draw_vertical_grid(game);
}

void	move_left(t_game *game)
{
	int	new_x;

	new_x = game->player_x - 1;
	if (game->map[game->player_y][new_x] == '1')
		return ;
	else
		new_pos(game, game->player_y, new_x);
	print_map(game);
}

void	move_right(t_game *game)
{
	int	new_x;

	new_x = game->player_x + 1;
	if (game->map[game->player_y][new_x] == '1')
		return ;
	else
		new_pos(game, game->player_y, new_x);
	print_map(game);
	draw_horizontal_grid(game);
	draw_vertical_grid(game);
}

void	move_down(t_game *game)
{
	int	new_y;

	new_y = game->player_y + 1;
	if (game->map[new_y][game->player_x] == '1')
		return ;
	else
		new_pos(game, new_y, game->player_x);
	print_map(game);
	draw_horizontal_grid(game);
	draw_vertical_grid(game);
}

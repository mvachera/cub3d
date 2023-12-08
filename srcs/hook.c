/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:42:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/08 20:46:11 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	disconnect(t_map *game)
{
	free_map(game->map);
	free_map(game->map_expand);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_map *game)
{
	if (keycode == ECHAP)
		disconnect(game);
	if (keycode == UP || keycode == 65362)
		move_up(game);
	if (keycode == LEFT || keycode == 65361)
		move_left(game);
	if (keycode == DOWN || keycode == 65364)
		move_down(game);
	if (keycode == RIGHT || keycode == 65363)
		move_right(game);
	return (0);
}

int move(t_map *game)
{
	if (game->key.q == 1)
		disconnect(game);
	if (game->key.w == 1)
		move_up(game);
	if (game->key.a == 1)
		move_left(game);
	if (game->key.s == 1)
		move_down(game);
	if (game->key.d == 1)
		move_right(game);
	print_map(game);
	return (0);

}

int	key_press(int keycode, t_map *game)
{
	if (keycode == ECHAP)
		game->key.q = 1;
	if (keycode == UP || keycode == 65362)
		game->key.w = 1;
	if (keycode == LEFT || keycode == 65361)
		game->key.a = 1;
	if (keycode == DOWN || keycode == 65364)
		game->key.s = 1;
	if (keycode == RIGHT || keycode == 65363)
		game->key.d = 1;
	return (0);
}
int	key_release(int keycode, t_map *game)
{
	if (keycode == ECHAP)
		game->key.q = 0;
	if (keycode == UP || keycode == 65362)
		game->key.w = 0;
	if (keycode == LEFT || keycode == 65361)
		game->key.a = 0;
	if (keycode == DOWN || keycode == 65364)
		game->key.s = 0;
	if (keycode == RIGHT || keycode == 65363)
		game->key.d = 0;
	return (0);
}

void	small_new_pos(t_map *game, int new_y, int new_x)
{
	if (game->player_y != new_y)
	{
		if (game->player_y > new_y)
		{
			while (game->map_expand[new_y][game->player_x] == '1')
				new_y++;
		}
		else
		{
			while (game->map_expand[new_y][game->player_x] == '1')
				new_y--;
		}
	}
	else if (game->player_x != new_x)
	{
		if (game->player_x > new_x)
		{
			while (game->map_expand[game->player_y][new_x] == '1')
				new_x++;
		}
		else
		{
			while (game->map_expand[game->player_y][new_x] == '1')
				new_x--;
		}
	}
	game->player_y = new_y;
	game->player_x = new_x;
}

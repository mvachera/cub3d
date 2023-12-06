/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:42:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/06 20:00:19 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	disconnect(t_game *game)
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

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ECHAP)
		disconnect(game);
	if (keycode == UP || keycode == 65362)
		mlx_loop_hook(game->mlx, move_up, game);
	if (keycode == LEFT || keycode == 65361)
		mlx_loop_hook(game->mlx, move_left, game);
	if (keycode == DOWN || keycode == 65364)
		mlx_loop_hook(game->mlx, move_down, game);
	if (keycode == RIGHT || keycode == 65363)
		mlx_loop_hook(game->mlx, move_right, game);
	return (0);
}

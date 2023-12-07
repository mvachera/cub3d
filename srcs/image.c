/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:16:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/06 20:05:17 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	init_single_texture(void **img_ptr, t_map *game, char *path)
// {
// 	*img_ptr = mlx_xpm_file_to_image(game->mlx, path, &game->size_x,
// 			&game->size_y);
// 	if (!*img_ptr)
// 	{
// 		ft_printf("Error\nUne image n'a pas ete initialiser correctement!\n");
// 		return (1);
// 	}
// 	return (0);
// }

// int	init_texture(t_map *game)
// {
// 	if (init_single_texture(&game->wall, game, "image/wall.xpm"))
// 		return (1);
// 	if (init_single_texture(&game->floor, game, "image/floor.xpm"))
// 		return (1);
// 	return (0);
// }

void	print_img(t_map *game, size_t i, size_t j)
{
	if (game->map_expand[i][j] == '1')
		mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0x000000);
	else if (game->map_expand[i][j] == '0')
		mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0xFFFFFF);
	else if (game->map_expand[i][j] == game->start_direction)
		mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0xFFFFFF);
}

void	print_map(t_map *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map_expand[i])
	{
		j = 0;
		while (game->map_expand[i][j])
		{
			print_img(game, i, j);
			j++;
		}
		i++;
	}
	draw_horizontal_grid(game);
	draw_vertical_grid(game);
	use_pixel(game, game->player_y, game->player_x);
}

void	print_window(t_map *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free_map(game->map);
		return ;
	}
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, game->height
			* 64, "cub3d");
	// if (init_texture(game))
	// {
	// 	return ;
	// }
	if (game->mlx_win == NULL)
	{
		free(game->mlx_win);
		free_map(game->map);
		return ;
	}
	print_map(game);
	mlx_hook(game->mlx_win, 17, (1L << 17), disconnect, game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_loop(game->mlx);
}

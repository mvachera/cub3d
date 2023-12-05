/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:16:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/05 19:32:26 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_single_texture(void **img_ptr, t_game *game, char *path)
{
	*img_ptr = mlx_xpm_file_to_image(game->mlx, path, &game->size_x,
			&game->size_y);
	if (!*img_ptr)
	{
		ft_printf("Error\nUne image n'a pas ete initialiser correctement!\n");
		return (1);
	}
	return (0);
}

int	init_texture(t_game *game)
{
	if (init_single_texture(&game->wall, game, "image/wall.xpm"))
		return (1);
	if (init_single_texture(&game->floor, game, "image/floor.xpm"))
		return (1);
	return (0);
}

void	print_img(t_game *game, size_t i, size_t j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, (j * 64),
			(i * 64));
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, (j * 64),
			(i * 64));
	else if (game->map[i][j] == game->start_direction)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, (j * 64),
			(i * 64));
		use_pixel(game, i * 64, j * 64);
	}
}

void	print_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			print_img(game, i, j);
			j++;
		}
		i++;
	}
	draw_horizontal_grid(game);
	draw_vertical_grid(game);
}

void	print_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free_map(game->map);
		return ;
	}
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, game->height
			* 64, "cub3d");
	if (init_texture(game))
	{
		return ;
	}
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

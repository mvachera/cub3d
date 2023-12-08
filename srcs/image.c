/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:16:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/08 21:15:48 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_img(int *buff, t_map *game, size_t i, size_t j)
{

	if (game->map_expand[i][j] == '1')
	{
		// printf(">>>>>>>>>%zu\n", j);
		*buff = 0x135465;
		// mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0x000000);
	}
	else if (game->map_expand[i][j] == '0')
		*buff = 0xABc789;
		// mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0xFFFFFF);
	// else if (game->map_expand[i][j] == game->start_direction)
	// 	mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0xFFFFFF);
}

void	print_map(t_map *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	void *img = mlx_new_image(game->mlx, game->width * 64, game->height * 64);
	int r;
	int *data = (int *)mlx_get_data_addr(img, &r, &r, &r);
	int **buff = malloc(sizeof(int*) * game->height * 64);
	// printf("MAXH = %i | MAXW = %i\n", game->height * 64, game->width * 64);
	for (int w = 0; w < game->width * 64; w++)
	{
		buff[w] = malloc(sizeof(int) * game->width * 64);

	}
	
	while (game->map_expand[i])
	{
		j = 0;
		// printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>%zu\n", i);
		while (game->map_expand[i][j])
		{
			print_img(&buff[i][j], game, i, j);
			j++;
		}
		i++;
	}
	for (int h = 0; h < game->height * 64; h++)
		for (int w = 0; w < game->width * 64; w++)
		{
			data[game->width * 64 * h + w] = buff[h][w];
			// printf(">>>>%x\n", buff[h][w]);
		}
	// exit(1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, 0, 0);
	// ft_memset(buff, 0, game->width * 64 * game->height * 64);
	mlx_destroy_image(game->mlx, img);
	// draw_horizontal_grid(game);
	// draw_vertical_grid(game);
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
	ft_memset(&game->key, 0, sizeof(t_key));
	mlx_loop_hook(game->mlx, &move, game);
	mlx_hook(game->mlx_win, 17, (1L << 17), disconnect, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, &key_release, game);
	mlx_loop(game->mlx);
}

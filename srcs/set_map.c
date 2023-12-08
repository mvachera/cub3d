/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:06:37 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/08 17:17:45 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	nb_line(t_map *game, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	game->height = i;
}

void	longest_line(t_map *game, char **tab)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > (size_t)max)
			max = ft_strlen(tab[i]);
		i++;
	}
	game->width = max;
}

void	set_map(t_map *game)
{
	game->size_x = 64;
	game->size_y = 64;
	nb_line(game, game->map);
	longest_line(game, game->map);
	// printf("player_y = %d, player_x = %d\n", game->player_y, game->player_x);
	game->player_x *= 64;
	game->player_y *= 64;
	game->player_x += 32;
	game->player_y += 32;
	// game->map_expand[game->player_y][game->player_x] = game->start_direction;
	// printf("la : ligne = %d, colonne = %d, char = %c\n", game->player_y, game->player_x, game->start_direction);
}

char	**create_new_map(t_map *game, char **map, int nb)
{
	char	**dst;
	int		mult;
	int		i;
	int		j;

	dst = ft_calloc(sizeof(char *), (nb * 64) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (map[i])
	{
		mult = 0;
		while (mult < 64)
		{
			dst[j] = ft_calloc(sizeof(char *), ((ft_strlen(map[i]) * 64) + 1));
			if (!dst[j])
			{
				while (--j >= 0)
					free(dst[j]);
				return (free(dst), NULL);
			}
			expand_cpy(game, map[i], dst[j]);
			j++;
			mult++;
		}
		i++;
	}
	return (dst);
}

void	expand_cpy(t_map *game, char *str, char *dst)
{
	int		mult;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		mult = 0;
		while (mult < 64)
		{
			if (str[i] == game->start_direction)
				str[i] = '0';
			dst[j] = str[i];
			j++;
			mult++;
		}
		i++;
	}
}

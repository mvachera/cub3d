/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:06:37 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/06 19:22:11 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map(t_game *game)
{
	game->size_x = 64;
	game->size_y = 64;
	game->width = 11;
	game->height = 9;
	game->player_x = 6 * 64;
	game->player_y = 5 * 64;
	game->start_direction = 'N';
}

char	**create_new_map(char **map, t_list *lst)
{
	char	**dst;
	int		mult;
	int		i;
	int		j;

	dst = calloc(sizeof(char *), ((lstnb(lst) * 64) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (map[i])
	{
		mult = 0;
		while (mult < 64)
		{
			dst[j] = calloc(sizeof(char *), ((strlen(map[i]) * 64) + 1));
			if (!dst[j])
			{
				while (--j >= 0)
					free(dst[j]);
				return (free(dst), NULL);
			}
			expand_cpy(map[i], dst[j]);
			j++;
			mult++;
		}
		i++;
	}
	return (dst);
}

void	expand_cpy(char *str, char *dst)
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
			dst[j] = str[i];
			j++;
			mult++;
		}
		i++;
	}
}

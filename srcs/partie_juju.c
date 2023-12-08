/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partie_juju.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:50 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/08 17:17:53 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	back_track(t_map *game)
{
	if (!game->map)
		return (0);
	game->map_expand = create_new_map(game, game->map, ft_len_tab(game->map));
	if (!game->map_expand)
		return (1);
	// for (int i = 0; game->map_expand[i]; i++)
	// 	printf("%s\n", game->map_expand[i]);
	return (0);
}

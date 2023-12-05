/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partie_juju.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:50 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/05 19:27:06 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	back_track(char *av1, t_game *game)
{
	static t_list	*all_line;

	all_line = NULL;
	extract_to_all_line(av1, &all_line);
	if (!all_line)
		return (0);
	game->map = map_parser(all_line);
	if (!game->map)
		return (0);
	free_stash(all_line);
	return (0);
}

void	set_map(t_game *game)
{
	game->size_x = 64;
	game->size_y = 64;
	game->width = 11;
	game->height = 9;
	game->player_x = 6;
	game->player_y = 5;
	game->start_direction = 'N';
}

char	**map_parser(t_list *all_line)
{
	char	**map_a_parser;
	t_list	*current;

	map_a_parser = finito2(all_line);
	if (map_a_parser == NULL)
		return (NULL);
	current = all_line;
	while (current && ft_strlen(current->content) <= 1)
		current = current->next;
	while (current && ft_strlen(current->content) > 1)
		current = current->next;
	if (finito(current, all_line, map_a_parser) == 0)
		return (NULL);
	return (map_a_parser);
}

int	finito(t_list *current, t_list *all_line, char **map_a_parser)
{
	while (current)
	{
		if (ft_strlen(current->content) > 1)
		{
			ft_printf("Error\nUne ligne vide a ete trouver!\n");
			free_stash(all_line);
			free_map(map_a_parser);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

char	**finito2(t_list *all_line)
{
	t_list	*current;
	char	**map_a_parser;
	int		i;

	i = 0;
	current = all_line;
	map_a_parser = malloc(sizeof(char *) * (lstnb(all_line) + 1));
	if (map_a_parser == NULL)
		return (NULL);
	while (current && ft_strlen(current->content) <= 1)
		current = current->next;
	while (current && ft_strlen(current->content) > 1)
	{
		map_a_parser[i] = cpy(current->content);
		if (map_a_parser[i] == NULL)
		{
			while (i >= 0)
				free(map_a_parser[i--]);
			return (NULL);
		}
		i++;
		current = current->next;
	}
	map_a_parser[i] = NULL;
	return (map_a_parser);
}

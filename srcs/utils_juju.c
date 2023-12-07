/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_juju.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:07:32 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/04 21:00:54 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	lstnb(t_list *all_line)
{
	t_list	*current;
	int		i;

	current = all_line;
	i = 0;
	while (current)
	{
		if (ft_strlen(current->content) > 1)
			i++;
		current = current->next;
	}
	return (i);
}

char	*cpy(char *all_line_content)
{
	char	*line;
	int		j;

	line = malloc(sizeof(char) * (ft_strlen(all_line_content) + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (all_line_content[j] && all_line_content[j] != '\n')
	{
		line[j] = all_line_content[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

void	free_map(char **map_a_parser)
{
	int	i;

	i = 0;
	while (map_a_parser[i])
	{
		free(map_a_parser[i]);
		i++;
	}
	free(map_a_parser);
}

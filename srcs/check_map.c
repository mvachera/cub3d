/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:42:16 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/07 18:42:21 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    good_item(char c)
{
    if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

int    check_char(char c)
{
    if (c != '0' && c != '1' && c != ' ' && c != '\t'
        && c != 'N' && c != 'S' && c != 'W' && c != 'E')
        return (printf("Error\nUn charactere non identifiable a ete trouver\n"),
            0);
    return (1);
}

int    check_wall2(char **tab, int i, int j)
{
    if (!tab[i - 1][j] || !tab[i + 1][j] || !tab[i][j - 1] || !tab[i][j + 1])
        return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
    if (good_item(tab[i - 1][j]) == 0)
        return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
    if (good_item(tab[i + 1][j]) == 0)
        return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
    if (good_item(tab[i][j - 1]) == 0)
        return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
    if (good_item(tab[i][j + 1]) == 0)
        return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
    return (1);
}

int    check_enter(t_map *game, char **tab)
{
    int    entree;
    int    i[2];

    entree = 0;
    i[0] = 0;
    while (tab[i[0]])
    {
        i[1] = 0;
        while (tab[i[0]][i[1]])
        {
            if (tab[i[0]][i[1]] == 'N' || tab[i[0]][i[1]] == 'S'
                || tab[i[0]][i[1]] == 'W' || tab[i[0]][i[1]] == 'E')
            {
                game->player_y = i[0];
                game->player_x = i[1];
                game->start_direction = tab[i[0]][i[1]];
                entree++;
            }
            i[1]++;
        }
        i[0]++;
    }
    if (entree != 1)
        return (printf("Error\nIl faut exactement une seule entree\n"), 0);
    return (1);
}

int    check_wall(char **tab)
{
    int    i;
    int    j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == '0' && !check_wall2(tab, i, j))
                return (0);
            else if (!check_char(tab[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

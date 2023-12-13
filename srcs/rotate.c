/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:48:58 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/13 18:44:06 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double degrees_to_radians(double degrees)
{
    return degrees * (PI / 180.0);
}

double radians_to_degrees(double radians)
{
    return radians * (180.0 / PI);
}

void rotate_left(t_map *game)
{
    game->player_direction -= 0.03;
    if (game->player_direction < 0)
        game->player_direction += 2 * PI;
    print_map(game);
}

void rotate_right(t_map *game)
{
    game->player_direction += 0.03;
    if (game->player_direction >= 2 * PI)
        game->player_direction -= 2 * PI;
    print_map(game);
}

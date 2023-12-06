/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:18:02 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/06 19:08:14 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	static t_game	game = {0};

	if (ac != 2)
		ft_printf("Error\nNombre d'argument incorrect!\n");
	else if (ac == 2 && back_track(av[1], &game) == 0)
	{
		set_map(&game);
		// for (int y = 0; game.map_expand[y]; y++)
		// 	printf("%s\n", game.map_expand[y]);
		print_window(&game);
	}
	return (0);
}

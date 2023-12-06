/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:18:28 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/06 19:45:58 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define CAM_RIGHT 65363
# define CAM_LEFT 65361
# define ECHAP 65307

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;

	void	*wall;
	void	*floor;
	char	**map;
	char	**map_expand;

	int		size_x;
	int		size_y;

	int		width;
	int		height;

	int		player_x;
	int		player_y;

	int		start_line;
	int		start_colonne;
	char	start_direction;
}			t_game;

void		all_line_new(t_list **all_line, char *line);
void		extract_to_all_line(char *av1, t_list **all_line);
int			back_track(char *av1, t_game *game);
char		**map_parser(t_list *all_line);
char		*cpy(char *all_line_content);
void		free_map(char **map_a_parser);
int			reste(char **map);
int			finito(t_list *current, t_list *all_line, char **map_a_parser);
int			check_all_line(t_list *all_line);
char		**finito2(t_list *all_line);
int			lstnb(t_list *all_line);
int			init_single_texture(void **img_ptr, t_game *game, char *path);
int			key_hook(int keycode, t_game *game);
int			disconnect(t_game *game);
int			init_texture(t_game *game);
void		print_img(t_game *game, size_t i, size_t j);
void		print_map(t_game *game);
void		print_window(t_game *game);
void		set_map(t_game *game);
void		use_pixel(t_game *game, int y, int x);
void		draw_circle(t_game *game, int x, int y, int size);
void		draw_ray(t_game *game, int x, int y, int size);
void		draw_horizontal_grid(t_game *game);
void		draw_vertical_grid(t_game *game);
void		new_pos(t_game *game, int new_y, int new_x);
int			move_up(t_game *game);
int			move_left(t_game *game);
int			move_right(t_game *game);
int			move_down(t_game *game);
char		**create_new_map(char **map, t_list *lst);
void		expand_cpy(char *str, char *dst);

#endif

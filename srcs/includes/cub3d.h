#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>

# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define CAM_RIGHT 65363
# define CAM_LEFT 65361
# define ECHAP 65307

typedef struct s_map
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		*F;
	int		*C;
	char	**map;
	char	start_direction;
	void	*mlx;
	void	*mlx_win;

	void	*wall;
	void	*floor;
	char	**map_expand;

	int		size_x;
	int		size_y;

	int		width;
	int		height;

	int		player_x;
	int		player_y;

}			t_map;

void		all_line_new(t_list **all_line, char *line);
void		extract_to_all_line(char *av1, t_list **all_line);
int			back_track(t_map *game);
char		**map_parser(t_list *all_line);
char		*cpy(char *all_line_content);
void		free_map(char **map_a_parser);
int			reste(char **map);
int			finito(t_list *current, t_list *all_line, char **map_a_parser);
int			check_all_line(t_list *all_line);
char		**finito2(t_list *all_line);
int			lstnb(t_list *all_line);
int			key_hook(int keycode, t_map *game);
int			disconnect(t_map *game);
void		print_img(t_map *game, size_t i, size_t j);
void		print_map(t_map *game);
void		print_window(t_map *game);
void		set_map(t_map *game);
void		use_pixel(t_map *game, int y, int x);
void		draw_circle(t_map *game, int x, int y, int size);
void		draw_ray(t_map *game, int x, int y, int size);
void		draw_horizontal_grid(t_map *game);
void		draw_vertical_grid(t_map *game);
void		new_pos(t_map *game, int new_y, int new_x);
int			move_up(t_map *game);
int			move_left(t_map *game);
int			move_right(t_map *game);
int			move_down(t_map *game);
char		**create_new_map(char **map, int nb);
void		expand_cpy(char *str, char *dst);
char		*ft_extract_file(char *path);
int			nswe_check(char **tab);
void		freestruc(t_map *map);
void		*struct_init(void);
void		free_tab(char **tab);
t_map		*ft_put_in_struct(char **map);
void		print_struct(t_map map);
char		**ft_spliit(char *str, char c);
int			check_wall(char **tab);
int			check_enter(t_map *game, char **tab);
char		*ft_strduup(char *source);
void		nb_line(t_map *game, char **tab);
void		longest_line(t_map *game, char **tab);

#endif
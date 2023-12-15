/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:43:05 by mvachera          #+#    #+#             */
/*   Updated: 2023/12/14 19:43:08 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define CAM_RIGHT 65363
# define CAM_LEFT 65361
# define ECHAP 65307
# define FOV 60

# define PI 3.14159265358979323846

typedef struct s_key
{
	int 		w;
	int 		s;
	int 		d;
	int 		a;
	int		q;
	int		c_l;
	int		c_r;
}	t_key;

typedef struct s_subray
{
	int		wall;
	float	collision_x;
	float	collision_y;
	float 	distance;
} t_subray;

typedef struct s_ray
{
	t_subray	ray_hor;
	t_subray	ray_ver;
	int		wall;
	float	collision_x;
	float	collision_y;
	float 	distance;
	double	angle;
}	t_ray;


typedef struct s_map
{
	char        *NO;
	char        *SO;
	char        *WE;
	char        *EA;
    int         *F;
    int         *C;
    char        **map;
	int			start_line;
    int			start_colonne;
    char		start_direction;
    void	*mlx;
	void	*mlx_win;
	int		hauteur;
	int		largeur;
	char	*wall_path[4];
	void	*wall;
	void	*floor;
	char	**map_expand;
	char		*path;
	int			nb_of_line;
	char		**file;
	int 	last_input;
	int		pre_last_input;
	int 	current_input; 
	t_ray		ray[FOV];
	float		ray_line[FOV];
	float		ray_offset[FOV];
	int			decalage_x;
	int			decalage_y;
	int		size_x;
	int		size_y;

	int		width;
	int		height;

	int		player_x;
	int		player_y;

	double	player_direction;
	t_key	key;
}				t_map;

float modulo(float value, float mod_value);
float conv_rad(float angle);
void	set_ray(t_ray *to_set, t_subray to_copy);
float	ft_find_collision(t_map *data, t_ray *ray, float (*raycast)(t_map*, t_ray*, float));
float	ft_raycasting_vertical(t_map *data, t_ray *ray, float to_add);
float	ft_raycasting_horizontal(t_map *data, t_ray *ray, float to_add);
void	ft_raycasting(t_map *data);
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
int			init_single_texture(void **img_ptr, t_map *game, char *path);
int			key_hook(int keycode, t_map *game);
int			disconnect(t_map *game);
int			init_texture(t_map *game);
void		print_map(t_map *game);
void		print_window(t_map *game);
void		set_map(t_map *game);
void		use_pixel(t_map *game, int y, int x);
void		draw_circle(t_map *game, int x, int y);
void		draw_ray(t_map *game, int x, int y, double angle);
void		draw_horizontal_grid(t_map *game);
void		draw_vertical_grid(t_map *game);
void	small_new_pos(t_map *game, int new_y, int new_x);
void		new_pos(t_map *game, int new_y, int new_x);
int			move_up(t_map *game);
int			move_left(t_map *game);
int			move_right(t_map *game);
int			move_down(t_map *game);
char		**create_new_map(t_map *game, char **map, int nb);
void		expand_cpy(t_map *game, char *str, char *dst);
char *ft_extract_file(char *path);
int nswe_check(char **tab);
void    freestruc(t_map *map);
void *struct_init();
void    free_tab(char **tab);
t_map *ft_put_in_struct(char **map);
void print_struct(t_map map);
char **ft_spliit(char *str, char c);
int    check_enter(t_map *game, char **tab);
int    check_wall(char **tab);
char	*ft_strduup(char *source);

//
int move(t_map *game);
int	key_press(int keycode, t_map *game);
int	key_release(int keycode, t_map *game);
void rotate_left(t_map *game);
void rotate_right(t_map *game);

#endif

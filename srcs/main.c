#include "cub3d.h"
 
int ft_check_2(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    if (!s1[i] && !s2[i])
        return (1);
    return (0);
}

int ft_check_name(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '.' && i > 0)
            if (ft_check_2(str+i, ".cub"))
                return (0);
        i++;
    }
    return (1);
}

char **ft_replace(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == '\n')
                map[i][j] = 0;
            j++;
        }
        i++;
    }
    return (map);
}

int main(int argc, char **argv)
{
    char *s_line;
    char **tab_map;
    t_map *map;

    if (argc != 2 || (argc == 2 && (!argv[1] || !*argv[1])))
        return (1);
    if (ft_check_name(argv[1]))
        return (1);
    s_line = ft_extract_file(argv[1]);
    if (!s_line)
        return (0);
    tab_map = ft_split(s_line, '\n');
    if (!nswe_check(tab_map))
        return (1);
    free_tab(tab_map);
    tab_map = ft_spliit(s_line, '\n');
    map = struct_init();
    map = ft_put_in_struct(tab_map);
    if (!check_wall(map->map) || !check_enter(map, map->map))
        return (1);
    print_struct(*map);
    if (back_track(*&map) == 0)
	{
		set_map(*&map);
		// for (int y = 0; game.map_expand[y]; y++)
		// 	printf("%s\n", game.map_expand[y]);
		print_window(*&map);
	}
    freestruc(*&map);
    free_tab(tab_map);
    free(s_line);
    return (0);
}

#include "cub3d.h"
char *put_str(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    while (str[j] && str[j] != '\n')
        j++;
    if (str[j] == '\n')
        str[j] = 0;
    return (str+i);
}

int *put_int_tab(char *str, int *tab)
{
    int i;
    int j;
    int flag;
    int start;

    flag = 0;
    j = 0;
    start = 0;
    i = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    while (str[i] && !flag)
    {
        start = i;
        while (str[i] && ft_isdigit(str[i]))
            i++;
        if (str[i] == ',' || !str[i] || str[i] == '\n')
        {
            if (!str[i])
                flag++;
            str[i] = '\0';
        }
        if (ft_isdigit(str[start]))
            tab[j++] = ft_atoi(str+start);
        if (!flag)
            i++;
    }
    return (tab);
}


t_map *pars(char *str, t_map *map)
{
    int i;

    i = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == 'N' && str[i+1] == 'O')
        map->NO = ft_strdup(put_str(str+2));
    else if (str[i] == 'S' && str[i+1] == 'O')
        map->SO = ft_strdup(put_str(str+2));
    else if (str[i] == 'W' && str[i+1] == 'E')
        map->WE = ft_strdup(put_str(str+2));
    else if (str[i] == 'E' && str[i+1] == 'A')
        map->EA = ft_strdup(put_str(str+2));
    else if (str[i] == 'F')
        map->F = put_int_tab(str+1, map->F);
    else if (str[i] == 'C')
        map->C = put_int_tab(str+1, map->C);
    return (map);
}

int check_pars(char *str)
{
    int i;

    i = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == 'N' && str[i+1] == 'O')
        return (1);
    if (str[i] == 'S' && str[i+1] == 'O')
        return (1);
    if (str[i] == 'W' && str[i+1] == 'E')
        return (1);
    if (str[i] == 'E' && str[i+1] == 'A')
        return (1);
    if (str[i] == 'F')
        return (1); 
    if (str[i] == 'C')
        return (1); 
    return (0);
}

int map_len(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

t_map *ft_put_in_struct(char **map)
{
    int i;
    int j;
    t_map *s_map;

    s_map = struct_init();
    i = 0;
    j = 0;
    while (map[i])
    {
        if (check_pars(map[i]))
            s_map = pars(map[i], *&s_map);
        i++;
    }
    i--;
    while (i > 0 && map[i][0] != '\n')
        i--;
    i++;
    s_map->map = ft_calloc(sizeof (char *), (map_len(map+i)+1));
    while (map[i+j])
    {
        s_map->map[j] = ft_strduup(map[i+j]);
        j++;
    }
    return (s_map);
}

#include "cub3d.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(s1[i+j] == ' ' || s1[i+j] == '\t')
        j++;
    while (s1[i+j] && s2[i])
    {
        if (s1[i+j] != s2[i])
            return (0);
        i++;
    }
    if (!s1[i+j] && !s2[i])
        return (1);
    return (0);
}

int valid_value(char *str)
{
    int i;
    int start;
    int flag;
    int checknb;

    checknb = 0;
    start = 0;
    flag = 0;
    i = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (!ft_isdigit(str[i]))
        return (0);
    while (str[i] && !flag)
    {
        start = i;
        while (str[i] && ft_isdigit(str[i]))
            i++;
        if (str[i] == ',' || !str[i])
        {
            checknb++;
            if (!str[i])
                flag++;
            str[i] = '\0';
        }
        if (ft_atoi(str+start) > 255 || ft_atoi(str+start) < 0 || !ft_isdigit(str[start]))
            return (0);
        if (!flag)
            i++;
    }
    if (checknb > 3)
        return 0;
    return  1;
}

int ft_check(char *str)
{
    int i;

    i = 0;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == 'N' && str[i+1] == 'O')
        if (ft_strcmp(str+(i+2), "./path_to_the_north_texture"))
            return (1);
    if (str[i] == 'S' && str[i+1] == 'O')
        if (ft_strcmp(str+(i+2), "./path_to_the_south_texture"))
            return (2);
    if (str[i] == 'W' && str[i+1] == 'E')
        if (ft_strcmp(str+(i+2), "./path_to_the_west_texture"))
            return (3);
    if (str[i] == 'E' && str[i+1] == 'A')
        if (ft_strcmp(str+(i+2), "./path_to_the_east_texture"))
            return (4);
    if (str[i] == 'F')
    {
        if (valid_value(str+(i+1)))
            return (5);
        return (-1);
    }
    if (str[i] == 'C')
    {
        if (valid_value(str+(i+1)))
            return (6);
        return (-1);
    }
    return (0);
}

int nswe_check(char **tab)
{
    int n;
    int s;
    int w;
    int e;
    int f;
    int c;
    int i;
    int value;

    i = 0;
    f = 0;
    c = 0;
    n = 0;
    s = 0;
    w = 0;
    e = 0;
    while (tab[i])
    {
        value = ft_check(tab[i]);
        if (value == 1)
            n++;
        if (value == 2)
            s++;
        if (value == 3)
            w++;
        if (value == 4)
            e++;
        if (value == 5)
            f++;
        if (value == 6)
            c++;
        if (value < 0)
            break;
        i++;
    }
    if (n != 1 || s != 1  || w != 1 || e != 1|| f != 1 || c != 1 )
        return (0);
    return (1);
}
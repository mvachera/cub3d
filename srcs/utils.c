#include "cub3d.h"


void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void *struct_init()
{
    static t_map map = {0};
    map.F = malloc(sizeof(int) * 3);
    map.C = malloc(sizeof(int) * 3);

    return (&map);
}

void print_struct(t_map map)
{
    int i;
    
    i = 0;
    printf("%s\n", map.NO);
    printf("%s\n", map.SO);
    printf("%s\n", map.WE);
    printf("%s\n", map.EA);
    printf("start line%d\n", map.start_line);
    printf("start colone%d\n", map.start_colonne);
    printf("start direction%c\n", map.start_direction);

    while (i < 3)
        printf("%d\n", map.F[i++]);
    i = 0;
    while (i < 3)
        printf("%d\n", map.C[i++]);
    i = 0;
    while (map.map[i])
        printf("%s\n", map.map[i++]);
}

void    freestruc(t_map *map)
{
    int i;

    i = 0;
    free(map->NO);
    free(map->SO);
    free(map->WE);
    free(map->EA);
    while (map->map[i])
        free(map->map[i++]);
    free(map->map);
    free(map->F);
    // i = 0;
    // while (i < 3)
    //     free((void*)map->C[i++]);
    free(map->C);
}

int ft_strlenn(char *str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\t')
            count += 4;
        count++;
        i++;
    }
    return (count);
}

char	*ft_strduup(char *source)
{
	int		size;
	int		i;
	char	*dup;
    int     j;
    int     k;

    k = 0;
    j = 0;
	size = ft_strlenn(source);
	i = 0;
	dup = ft_calloc(sizeof (char), size + 1);
	if (!(dup))
		return (NULL);
	while (source[i] != '\0' && source[i] != '\n')
	{
        if (source[i] == '\t')
        {
            j = -1;
            while (++j < 4)
            {
                dup[i+k] = ' ';
                k++;
            }
            k--;
            i++;
        }
		dup[i+k] = source[i];
		i++;
	}
	return (dup);
}

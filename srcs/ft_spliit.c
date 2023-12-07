#include "cub3d.h"

int nb_w(char *str, char c)
{
    int  i;
    int count;

    count = 1;
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}
int len_w(char *str, char c)
{
    int i;
    int count;
    
    count = 1;
    i = 0;
    while (str[i])
    {
        count ++;
        if (str[i] == c)
            break;
        i++;
    }
    return (count);
}
char **ft_spliit(char *str, char c)
{
    int i;
    int j;
    int k;
    char **tab;

    j = 0;
    k = 0;
    i = 0;
    tab = ft_calloc(sizeof(char *), (nb_w(str, c) + 1));
    if (!tab)
        return (NULL);
    while (str[i])
    {
        tab[j] = ft_calloc(sizeof(char), (len_w(str+i, c) + 2));
        if (!tab[j])
            return (free_tab(tab), NULL);
        k = 0;
        while (str[i])
        {
            tab[j][k] = str[i];
            if (str[i] == c)
            {
                i++;
                j++;
                break;
            }
            k++;
            i++;
        }
    }
    return (tab);
}

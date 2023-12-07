#include "cub3d.h"

int ft_ispace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\b')
        return (1);
    return (0);
}

int check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!ft_isalnum(line[i]) && line[i] != '.' && line[i] != '/' 
            && line[i] != ',' && !ft_ispace(line[i]) && line[i] != '_')
            return (1);
        i++;
    }
    return (0);
}

char *ft_extract_file(char *path)
{
    char *line;
    char *super_line;

    int     fd;

    line = NULL;
    super_line = NULL;
    fd = open(path , O_RDONLY);
    if (fd == -1)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd, 0);
        if (line == NULL)
        {
            get_next_line(3, 1);
            free(line);
            break;
        }
        if (check_line(line))
        {
            get_next_line(3, 1);
            free(line);
            if (super_line)
                free(super_line);
            return (NULL);
        }
        super_line = ft_strjoin(super_line, line);
        free(line);
    }
    return (super_line);
}
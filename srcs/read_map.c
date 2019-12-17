/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:16:51 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/17 18:08:47 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     get_height(char *map)
{
    char *line;
    int fd;
    int height;

    fd = open(map, O_RDONLY, 0);
    height = 0;
    while(get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int     get_width(char *map)
{
    char *line;
    int fd;
    int width;

    fd = open(map, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_count_words(line, ' ');
    free(line);
    close(fd);
    return (width);
}

void    fill_matrix(int *z_line, char *line)
{
    char **nbrs;
    int i;

    nbrs = ft_strsplit(line, ' ');
    i = 0;
    while (nbrs[i])
    {
        z_line[i] = ft_atoi(nbrs[i]);
        i++;
        free(nbrs[i]);
    }
    free(nbrs);
}

void    read_map(char *map, t_fdf *data)
{
    int fd;
    char *line;
    int i;

    data->height = get_height(map);
    data->width = get_width(map);
    data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width +1));
    fd = open(map, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->z_matrix[i], line);
        free(line);
        i++;
    }
    data->z_matrix[i] = NULL;
    close(fd);
}
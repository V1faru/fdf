/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:16:51 by amurtone          #+#    #+#             */
/*   Updated: 2020/01/09 13:05:14 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_mem_alloc(char *map, int hw)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(map, O_RDONLY, 0);
	if (hw)
	{
		ret = 0;
		while (get_next_line(fd, &line))
		{
			ret++;
			free(line);
		}
	}
	else
	{
		get_next_line(fd, &line);
		ret = ft_count_words(line, ' ');
		free(line);
	}
	close(fd);
	return (ret);
}

int		fill_matrix(char *line, t_fdf **dots, int y)
{
	char	**nbrs;
	int		x;

	if (!(nbrs = ft_strsplit(line, ' ')))
		exit(1);
	x = 0;
	while (nbrs[x])
	{
		dots[y][x].z = ft_atoi(nbrs[x]);
		dots[y][x].x = x;
		dots[y][x].y = y;
		dots[y][x].is_last = 0;
		free(nbrs[x]);
		x++;
	}
	free(nbrs);
	dots[y][--x].is_last = 1;
	return (x);
}

t_fdf	**read_map(char *map, t_fdf *data)
{
	t_fdf	**dots;
	char	*line;
	int		fd;
	int		y;

	data->height = get_mem_alloc(map, 1);
	data->width = get_mem_alloc(map, 0);
	if (!(dots = (t_fdf **)malloc(sizeof(t_fdf *) * (data->height + 1))))
		exit(1);
	y = 0;
	while (y < data->height)
	{
		if (!(dots[y++] = (t_fdf *)malloc(sizeof(t_fdf) * (data->width + 1))))
			exit(1);
	}
	fd = open(map, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_matrix(line, dots, y++);
		free(line);
	}
	dots[y] = NULL;
	close(fd);
	return (dots);
}

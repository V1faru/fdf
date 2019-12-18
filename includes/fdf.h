/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:05:38 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/18 13:02:55 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "fdf.h"
# include <mlx.h>
# include "../libft/libft.h"

typedef struct      s_fdf
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;


    void    *mlx_ptr;
    void    *win_ptr;
}                   t_fdf;

void    read_map(char *map, t_fdf *data);
int		ft_count_words(const char *s, char c);
void    brsham(float x, float y, float x1, float y1, t_fdf *data);
void    draw_lines(t_fdf *data);

#endif
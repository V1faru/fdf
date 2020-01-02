/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andreas <Andreas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:05:38 by amurtone          #+#    #+#             */
/*   Updated: 2020/01/02 11:25:50 by Andreas          ###   ########.fr       */
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
# include "../resources/minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct      s_fdf
{
    int width;
    int height;
    float x;
    float y;
    float z;
    int   is_last;
    int zoom;
    int scale;
    int scale_z;
    int color;
    int shift_x;
    int shift_y;
    int is_isometric;
    double  angle;
    int     w_x;
    int     w_y;
    void    *mlx_ptr;
    void    *win_ptr;
}                   t_fdf;

typedef struct      s_data
{
    t_fdf *data;
    t_fdf **matrix;
}                   t_data;

t_fdf   **read_map(char *map, t_fdf *data);
int		ft_count_words(const char *s, char c);
void    brsham(t_fdf a, t_fdf b, t_fdf *data);
void    draw_lines(t_fdf **matrix, t_fdf *data);
void    print_menu(t_fdf *data);
void    isometric(t_fdf *dot, double angle);
void    set_params(t_fdf *a, t_fdf *b, t_fdf *data);
int		deal_key(int key, t_data *data);
void	new_window(int key, t_fdf *data, t_fdf **matrix);


#endif

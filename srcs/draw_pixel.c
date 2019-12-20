/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:58:11 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/20 14:34:18 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

# define MAX1(a,b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    brsham(float x, float y, float x1, float y1, t_fdf *data)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];
    /* -----ZOOM----- */
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    /* -----COLOR----- */
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    /* -----3D----- */
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    /* -----shift----- */
    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;

    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX1(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }
}

void    draw_lines(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while(y < data->height)
    {
        x = 0;
        while(x < data->width)
        {
            if (x < data->width - 1)
                brsham(x, y, x + 1, y, data);
            if (y < data->height - 1)
                brsham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}
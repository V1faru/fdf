/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andreas <Andreas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:26:28 by Andreas           #+#    #+#             */
/*   Updated: 2019/12/29 23:51:35 by Andreas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    zoom(t_fdf *a, t_fdf *b, t_fdf *data)
{
    a->x *= data->scale;
    a->y *= data->scale;
	b->x *= data->scale;
	b->y *= data->scale;
	a->z *= data->scale_z;
	b->z *= data->scale_z;
}

void    set_params(t_fdf *a, t_fdf *b, t_fdf *data)
{
    zoom(a, b, data);
    if (data->is_isometric)
    {
        isometric(a, data->angle);
        isometric(b, data->angle);
    }
    a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;

}
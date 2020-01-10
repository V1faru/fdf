/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:25:59 by Andreas           #+#    #+#             */
/*   Updated: 2020/01/09 13:20:11 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset(t_data *data)
{
	data->data->scale = 30;
	data->data->scale_z = 1;
	data->data->is_isometric = 1;
	data->data->angle = 0.523599;
	data->data->w_x = 1500;
	data->data->w_y = 1000;
	data->data->shift_x = data->data->w_x / 2.5;
	data->data->shift_y = data->data->w_y / 3;
	scale_to_window(data);
}

int		is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == 125 || key == 126 || key == 123 || key == 124 ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22 || key == 36);
}

void	do_key(int key, t_data *data)
{
	if (key == 24 || key == 69)
		data->data->scale += 3;
	if (key == 27 || key == 78)
		data->data->scale -= 3;
	if (key == 91 || key == 28)
		data->data->scale_z += 1;
	if (key == 84 || key == 19)
		data->data->scale_z -= 1;
	if (key == 126)
		data->data->shift_y -= 10;
	if (key == 125)
		data->data->shift_y += 10;
	if (key == 123)
		data->data->shift_x -= 10;
	if (key == 124)
		data->data->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		data->data->is_isometric = (data->data->is_isometric) ? 0 : 1;
	if (key == 86 || key == 21)
		data->data->angle += 0.05;
	if (key == 88 || key == 22)
		data->data->angle -= 0.05;
	if (key == 36)
		reset(data);
}

int		deal_key(int key, t_data *data)
{
	if (is_key(key))
	{
		mlx_clear_window(data->data->mlx_ptr, data->data->win_ptr);
		do_key(key, data);
		print_menu(data->data);
		draw_lines(data->matrix, data->data);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, data);
	if (key == 53)
	{
		mlx_destroy_window(data->data->mlx_ptr, data->data->win_ptr);
		free(data->matrix);
		exit(0);
	}
	return (0);
}

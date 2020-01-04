/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:25:59 by Andreas           #+#    #+#             */
/*   Updated: 2020/01/04 12:27:47 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset(t_fdf *data)
{
	data->scale = 30;
    data->scale_z = 1;
    data->is_isometric = 1;
    data->angle = 0.7;
    data->w_x = 1000;
    data->w_y = 1000;
    data->shift_x = data->w_x / 2.5;
	data->shift_y = data->w_y / 3;
}

int		is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == 125 || key == 126 || key == 123 || key == 124 ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22 || key == 36);
}

void	do_key(int key, t_fdf *data)
{
	if (key == 24 || key == 69)
		data->scale += 3;
	if (key == 27 || key == 78)
		data->scale -= 3;
	if (key == 91 || key == 28)
		data->scale_z += 1;
	if (key == 84 || key == 19)
		data->scale_z -= 1;
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		data->is_isometric = (data->is_isometric) ? 0 : 1;
	if (key == 86 || key == 21)
		data->angle += 0.05;
	if (key == 88 || key == 22)
		data->angle -= 0.05;
	if (key == 36)
		reset(data);
}

int		deal_key(int key, t_data *data)
{
	ft_putnbr(key);
	ft_putchar(' ');
	if (is_key(key))
	{
		mlx_clear_window(data->data->mlx_ptr, data->data->win_ptr);
		do_key(key, data->data);
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
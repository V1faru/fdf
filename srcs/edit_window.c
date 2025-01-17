/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:54:47 by Andreas           #+#    #+#             */
/*   Updated: 2020/01/07 14:49:08 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_win_size(int key, t_fdf *data)
{
	if ((key == 0 && data->w_y <= 500) || (key == 6 && data->w_x <= 500))
		return (1);
	if ((key == 1 && data->w_y > 1000) || (key == 7 && data->w_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_fdf *data)
{
	static	int old_x;
	static	int old_y;

	if (data->w_x != 2560)
	{
		old_x = data->w_x;
		old_y = data->w_y;
	}
	data->w_x = (data->w_x == 2560) ? old_x : 2560;
	data->w_y = (data->w_y == 1400) ? old_y : 1400;
}

void	change_window_size(int key, t_fdf *data)
{
	if (check_win_size(key, data))
		return ;
	if (key == 6)
		data->w_x -= 100;
	if (key == 7)
		data->w_x += 100;
	if (key == 0)
		data->w_y -= 100;
	if (key == 1)
		data->w_y += 100;
	if (key == 3)
		full_screen(data);
}

void	new_window(int key, t_data *data)
{
	change_window_size(key, data->data);
	mlx_destroy_window(data->data->mlx_ptr, data->data->win_ptr);
	data->data->mlx_ptr = mlx_init();
	data->data->win_ptr = mlx_new_window(
		data->data->mlx_ptr, data->data->w_x, data->data->w_y, "FDF");
	data->data->shift_x = data->data->w_x / 3;
	data->data->shift_y = data->data->w_y / 3;
	draw_lines(data->matrix, data->data);
	mlx_key_hook(data->data->win_ptr, deal_key, data);
	mlx_loop(data->data->mlx_ptr);
}

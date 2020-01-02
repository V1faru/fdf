/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andreas <Andreas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:54:47 by Andreas           #+#    #+#             */
/*   Updated: 2019/12/30 20:43:50 by Andreas          ###   ########.fr       */
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
	static int old_x;
	static int old_y;

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

void	new_window(int key, t_fdf *data, t_fdf **matrix)
{
	change_window_size(key, data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_x, data->w_y, "FDF");
	data->shift_x = data->w_x / 3;
	data->shift_y = data->w_y / 3;
	draw_lines(matrix, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
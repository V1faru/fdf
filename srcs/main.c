/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:00:24 by amurtone          #+#    #+#             */
/*   Updated: 2020/01/09 13:04:04 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	initialize(t_fdf *data)
{
	data->scale = 30;
	data->scale_z = 1;
	data->is_isometric = 1;
	data->angle = 0.523599;
	data->w_x = 1920;
	data->w_y = 1080;
	data->shift_x = data->w_x / 2.5;
	data->shift_y = data->w_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_x, data->w_y, "FDF");
}

void	scale_to_window(t_data *data)
{
	int		y;

	y = 0;
	while (data->matrix[y])
		y++;
	if (y >= 30)
		data->data->scale = 21;
	if (y >= 100)
		data->data->scale = 6;
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		error_msg("usage: ./fdf map.fdf");
	}
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(data->data = (t_fdf *)malloc(sizeof(t_fdf))))
		exit(1);
	data->matrix = read_map(av[1], data->data);
	initialize(data->data);
	scale_to_window(data);
	draw_lines(data->matrix, data->data);
	mlx_key_hook(data->data->win_ptr, deal_key, data);
	mlx_loop(data->data->mlx_ptr);
	return (0);
}

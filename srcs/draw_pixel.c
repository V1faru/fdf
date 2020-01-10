/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:58:11 by amurtone          #+#    #+#             */
/*   Updated: 2020/01/09 11:16:32 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	mod(float i)
{
	return (i < 0) ? -i : i;
}

void	brsham(t_fdf a, t_fdf b, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		color;

	set_params(&a, &b, data);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = MAX1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	color = (b.z || a.z) ? 0xffe019 : 0x920dff;
	color = (b.z != a.z) ? 0xffe019 : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	draw_lines(t_fdf **matrix, t_fdf *data)
{
	int		x;
	int		y;

	print_menu(data);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				brsham(matrix[y][x], matrix[y + 1][x], data);
			if (!matrix[y][x].is_last)
				brsham(matrix[y][x], matrix[y][x + 1], data);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}

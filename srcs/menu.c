/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:58:37 by Andreas           #+#    #+#             */
/*   Updated: 2020/01/09 09:09:45 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf *data)
{
	char	*menu;

	menu = "arrow keys: up, down, left & right to move picture";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0x02ed8f, menu);
	menu = "5 or space: 3d/2d mode; +, -: zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0x02ed8f, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0x02ed8f, menu);
	menu = "return: reset picture";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x02ed8f, menu);
	menu = "a/s: + / -  window height; z/x +/- window width";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 65, 0x02ed8f, menu);
	menu = "f: full screen mode";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0x02ed8f, menu);
	menu = "esc: quit, close the program";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 95, 0x02ed8f, menu);
}

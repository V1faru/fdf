/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:00:24 by amurtone          #+#    #+#             */
/*   Updated: 2020/01/04 15:38:01 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    initialize(t_fdf *data)
{
    data->scale = 30;
    data->scale_z = 1;
    data->is_isometric = 1;
    data->angle = 0.7;
    data->w_x = 1000;
    data->w_y = 1000;
    data->shift_x = data->w_x / 2.5;
	data->shift_y = data->w_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_x, data->w_y, "FDF");
}

int     main(int ac, char **av)
{
    t_data    *data;

    if (ac == 2)
    {
        data = (t_data *)malloc(sizeof(t_data));
        data->data = (t_fdf *)malloc(sizeof(t_fdf));
        data->matrix = read_map(av[1], data->data);
        initialize(data->data);
        draw_lines(data->matrix, data->data);
        mlx_key_hook(data->data->win_ptr, deal_key, data);
      /*  mlx_hook(data->data->win_ptr, 4, 0, hook_mousedown, data);
	    mlx_hook(data->data->win_ptr, 5, 0, hook_mouseup, data);
	    mlx_hook(data->data->win_ptr, 6, 0, hook_mousemove, data);
*/        mlx_loop(data->data->mlx_ptr);
   }
   


}
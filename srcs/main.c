/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:00:24 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/17 17:25:05 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     main()
{
    /*
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();   
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "super awesome");
    mlx_loop(mlx_ptr);
    */
   t_fdf *data;

   data = (t_fdf *)malloc(sizeof(t_fdf));
   read_map(data);


}
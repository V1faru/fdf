/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:00:24 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/17 18:27:07 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     main(int ac, char **av)
{
    /*
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();   
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "super awesome");
    mlx_loop(mlx_ptr);
    */
   int i;
   int j;
   t_fdf *data;
 
   data = (t_fdf *)malloc(sizeof(t_fdf));
   if (ac == 2)
   {
        read_map(av[1], data);
        i = 0;
        while (i < data->height)
        {
            j = 0;
            while(j < data->width)
            {
                ft_putnbr(data->z_matrix[i][j]);
                ft_putchar(' ');
                j++;
            }
            i++;
        }
   }
   


}
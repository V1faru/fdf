/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:00:24 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/18 14:52:21 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     deal_key(int key/*, t_fdf *data*/)
{
    ft_putnbr(key);
    ft_putchar('\n');
    return (0);
}

int     main(int ac, char **av)
{
    t_fdf    *data;

    if (ac == 2)
    {
        data = (t_fdf *)malloc(sizeof(t_fdf));
        read_map(av[1], data);
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fdf super awesome");
        data->zoom = 20;
        draw_lines(data);
        mlx_key_hook(data->win_ptr, deal_key, data);
        mlx_loop(data->mlx_ptr);
   }
   


}
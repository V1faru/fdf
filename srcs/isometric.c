/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andreas <Andreas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:36:42 by Andreas           #+#    #+#             */
/*   Updated: 2019/12/29 15:45:16 by Andreas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    isometric(t_fdf *dot, double angle)
{
    dot->x = (dot->x - dot->y) * cos(angle);
    dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
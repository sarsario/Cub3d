/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:04:11 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/28 18:47:22 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** The purpose of the ray casting in this project is to determine the
** coordinates p1 and p2 of the obstacles. Still not sure if it is p1 and p2 on
** the same line or p1 and p2 on the same column. With p1 and p2, we can then
** draw a line between them using the draw_line function.
** Concerns: draw_line draws one color. What about textures?
*/

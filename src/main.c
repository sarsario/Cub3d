/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:59:31 by osarsari          #+#    #+#             */
/*   Updated: 2024/04/04 10:55:59 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		error_msg("pls provide just 1 scene description (.cub) file\n");
		return (1);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset((void *)game, 0, sizeof(t_game));
	if (!init_checks(game, av[1]))
		ft_free_checks(game);
	if (!init_game(game))
		ft_free_game(game);
	return (0);
}

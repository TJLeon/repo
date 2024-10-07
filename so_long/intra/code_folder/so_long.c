/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:13:52 by leotan            #+#    #+#             */
/*   Updated: 2024/09/26 15:00:46 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\nMap File"), 1);
	game.map = get_map(fd);
	game_init(&game);
	mlx_hook(game.mlx_win, 2, 0, (*key_press), &game);
	mlx_hook(game.mlx_win, 17, 0, (*game_exit), NULL);
	mlx_loop(game.mlx);
}

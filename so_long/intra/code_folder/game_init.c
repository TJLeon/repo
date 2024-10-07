/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:32:01 by leotan            #+#    #+#             */
/*   Updated: 2024/09/25 17:08:44 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_init(t_game *game)
{
	char	*p;
	int		dummy;
	size_t	index;

	p = "xpm_folder/ground.xpm";
	game->mlx_img[0] = mlx_xpm_file_to_image(game->mlx, p, &dummy, &dummy);
	p = "xpm_folder/wall.xpm";
	game->mlx_img[1] = mlx_xpm_file_to_image(game->mlx, p, &dummy, &dummy);
	p = "xpm_folder/player.xpm";
	game->mlx_img[2] = mlx_xpm_file_to_image(game->mlx, p, &dummy, &dummy);
	p = "xpm_folder/c.xpm";
	game->mlx_img[3] = mlx_xpm_file_to_image(game->mlx, p, &dummy, &dummy);
	p = "xpm_folder/exit.xpm";
	game->mlx_img[4] = mlx_xpm_file_to_image(game->mlx, p, &dummy, &dummy);
	index = 0;
	while (index < 5)
		if (game->mlx_img[index++] == NULL)
			exit(write(2, "Error\nMLX Img Init Fail\n", 24));
}

static void	get_res(t_game *game, size_t *x, size_t *y)
{
	size_t	index;

	index = 0;
	while (game->map[index] != NULL)
		index++;
	*y = index * 64;
	index = 0;
	while (game->map[0][index] != '\0')
		index++;
	*x = index * 64;
}

void	game_init(t_game *game)
{
	size_t	x;
	size_t	y;

	game->map_coin = get_map_c_total(game->map);
	get_map_pos(game);
	game->p_move = 0;
	game->p_coin = 0;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit(write(2, "Error\nMLX Init Fail\n", 20));
	img_init(game);
	get_res(game, &x, &y);
	game->mlx_win = mlx_new_window(game->mlx, x, y, "so_long");
	if (game->mlx_win == NULL)
		exit(write(2, "Error\nMLX Window Fail\n", 22));
	render_map(game);
}

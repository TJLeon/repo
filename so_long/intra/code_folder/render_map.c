/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:32:38 by leotan            #+#    #+#             */
/*   Updated: 2024/09/25 12:33:22 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_object(t_game *g, size_t y, size_t x, char o)
{
	if (o == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_img[0], x, y);
	if (o == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_img[1], x, y);
	if (o == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_img[2], x, y);
	if (o == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_img[3], x, y);
	if (o == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_img[4], x, y);
}

void	render_map(t_game *game)
{
	size_t	w_i;
	size_t	l_i;

	w_i = 0;
	while (game->map[w_i] != NULL)
	{
		l_i = 0;
		while (game->map[w_i][l_i] != '\0')
		{
			if (game->map[w_i][l_i] != '1')
			{
				render_object(game, w_i * 64, l_i * 64, '0');
				if (w_i == game->e_w && l_i == game->e_l)
					render_object(game, w_i * 64, l_i * 64, 'E');
				if (game->map[w_i][l_i] == 'P')
					render_object(game, w_i * 64, l_i * 64, 'P');
				if (game->map[w_i][l_i] == 'C')
					render_object(game, w_i * 64, l_i * 64, 'C');
			}
			else
				render_object(game, w_i * 64, l_i * 64, '1');
			l_i++;
		}
		w_i++;
	}
}

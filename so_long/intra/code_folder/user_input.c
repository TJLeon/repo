/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 03:58:07 by leotan            #+#    #+#             */
/*   Updated: 2024/09/26 03:58:35 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	write(1, "Exit Successful\n", 16);
	exit(0);
}

static void	ft_put_positive_number(size_t n)
{
	if (n > 9)
		ft_put_positive_number(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

static void	move_player(t_game *game, size_t to_w, size_t to_l)
{
	game->p_move++;
	write(1, "Movement Count: ", 17);
	ft_put_positive_number(game->p_move);
	write(1, "\n", 1);
	if (game->map[to_w][to_l] == 'C')
		game->p_coin++;
	if (game->map[to_w][to_l] == 'E' && game->p_coin == game->map_coin)
		game_exit(0, NULL);
	game->map[to_w][to_l] = 'P';
	if (game->p_w == game->e_w && game->p_l == game->e_l)
		game->map[game->p_w][game->p_l] = 'E';
	else
		game->map[game->p_w][game->p_l] = '0';
	game->p_w = to_w;
	game->p_l = to_l;
}

int	key_press(int keycode, void *p)
{
	t_game	*game;

	if (keycode == 53)
		game_exit(0, NULL);
	game = p;
	if (keycode == 13 && game->map[game->p_w - 1][game->p_l] != '1')
		move_player(game, game->p_w - 1, game->p_l);
	if (keycode == 0 && game->map[game->p_w][game->p_l - 1] != '1')
		move_player(game, game->p_w, game->p_l - 1);
	if (keycode == 1 && game->map[game->p_w + 1][game->p_l] != '1')
		move_player(game, game->p_w + 1, game->p_l);
	if (keycode == 2 && game->map[game->p_w][game->p_l + 1] != '1')
		move_player(game, game->p_w, game->p_l + 1);
	if (mlx_clear_window(game->mlx, game->mlx_win) == 0)
		exit(write(2, "Error\nMLX Window Clear Failed\n", 30));
	render_map(game);
	return (0);
}

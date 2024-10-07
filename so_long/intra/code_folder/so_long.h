/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:54:08 by leotan            #+#    #+#             */
/*   Updated: 2024/09/26 03:57:35 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_game
{
	char	**map;
	size_t	map_coin;
	size_t	e_w;
	size_t	e_l;
	size_t	p_w;
	size_t	p_l;
	size_t	p_move;
	size_t	p_coin;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img[5];
}	t_game;

void	ft_bzero(void *ptr, size_t len);
void	*ft_calloc(size_t len, size_t byte);
size_t	ft_strlen(const char *str);
char	*get_file(int fd);
void	map_valid_character(char *file);
void	map_valid_count(char *file);
size_t	get_map_width(char *file);
size_t	get_map_length(char *file);
char	**file_to_map(char *file);
void	map_valid_border(char **map);
char	**copy_map(char **map);
void	floodfield(char **map);
char	**get_map(int fd);
size_t	get_map_c_total(char **map);
void	get_map_pos(t_game *game_info);
void	render_map(t_game *game);
void	game_init(t_game *game);
int		game_exit(int keycode, void *param);
int		key_press(int keycode, void *p);

#endif

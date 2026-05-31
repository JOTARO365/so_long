/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

static void	handle_tile(t_game *game, int nx, int ny)
{
	char	tile;

	tile = game->map.grid[ny][nx];
	if (tile == 'C')
	{
		game->collected++;
		game->map.grid[ny][nx] = '0';
	}
	else if (tile == 'E')
	{
		ft_printf("You win! Total moves: %d\n", game->moves);
		free_game(game);
		exit(0);
	}
}

static void	try_move(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	tile;

	nx = game->px + dx;
	ny = game->py + dy;
	tile = game->map.grid[ny][nx];
	if (tile == '1')
		return ;
	if (tile == 'E' && game->collected < game->map.collectibles)
		return ;
	game->px = nx;
	game->py = ny;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	handle_tile(game, nx, ny);
	render_map(game);
}

int	handle_key(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		free_game(game);
		exit(0);
	}
	if (key == KEY_W || key == KEY_UP)
		try_move(game, 0, -1);
	else if (key == KEY_S || key == KEY_DOWN)
		try_move(game, 0, 1);
	else if (key == KEY_A || key == KEY_LEFT)
		try_move(game, -1, 0);
	else if (key == KEY_D || key == KEY_RIGHT)
		try_move(game, 1, 0);
	return (0);
}

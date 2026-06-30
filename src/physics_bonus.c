/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_vert(t_game *game, int new_y, int dir)
{
	int	nt;

	nt = new_y / TILE;
	if (nt == game->py_px / TILE)
	{
		game->py_px = new_y;
		game->py = nt;
		return ;
	}
	if (dir > 0 && (nt >= game->map.height
			|| game->map.grid[nt][game->px] == '1'))
	{
		game->py_px = (nt - 1) * TILE;
		game->vy = 0;
	}
	else if (dir < 0 && (nt < 0
			|| game->map.grid[nt][game->px] == '1'))
	{
		game->py_px = (nt + 1) * TILE;
		game->vy = 0;
	}
	else
		game->py_px = new_y;
	game->py = game->py_px / TILE;
}

void	reach_exit(t_game *game)
{
	if (game->level <= 0)
	{
		ft_printf("You win! Moves: %d\n", game->moves);
		free_game(game);
		exit(0);
	}
	ft_printf("Level %d clear! Moves: %d\n", game->level, game->moves);
	next_level(game);
}

static void	check_tile(t_game *game)
{
	char	tile;

	tile = game->map.grid[game->py][game->px];
	if (tile == 'C')
	{
		game->collected++;
		game->map.grid[game->py][game->px] = '0';
	}
	else if (tile == 'E' && game->collected >= game->map.collectibles)
		reach_exit(game);
}

void	apply_gravity(t_game *game)
{
	int	new_y;
	int	is_grounded;

	is_grounded = (game->py + 1 < game->map.height
			&& game->map.grid[game->py + 1][game->px] == '1'
			&& game->py_px % TILE == 0);
	if (is_grounded && game->vy >= 0)
		game->vy = 0;
	else
	{
		game->vy += GRAVITY_V;
		if (game->vy > MAX_FALL_V)
			game->vy = MAX_FALL_V;
	}
	new_y = game->py_px + game->vy;
	if (game->vy != 0)
		move_vert(game, new_y, game->vy);
	check_tile(game);
	render_map(game);
}
